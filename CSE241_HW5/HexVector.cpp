
#include <iostream>
#include <iterator>
#include <vector>
#include <fstream>
#include <time.h>
#include <string>
#include "AbstractHex.h"
#include "HexVector.h"
#include <time.h>
using namespace std;


bool HexVector::right_check(const int &move1,const int &move2){
    auto it = hexCells.begin();
    for(int i=0; i<(move1*getSizeOfBoard())+move2 ; i++)
        it++;
    int size = getSizeOfBoard();
    position temp =  (*it).getCPosition();
    if(temp == user1){
        (*it).setCPosition(win1);
        if(temp == user1 && move2 == getSizeOfBoard()-1){
            return true;
        }
        else{
            if(move1-1 >= 0 && (*(prev(it,size))).getCPosition() == user1){                
                if(right_check(move1-1, move2)){
                    
                    return true;
                }
            }
            if(move1-1 >= 0 && move2+1 < getSizeOfBoard() && (*(next(it,size-1))).getCPosition() == user1){
                if(right_check(move1-1, move2+1)){
                  
                    return true;
                }
            }
            if(move2-1 >= 0 && (*(prev(it,1))).getCPosition() == user1){
                if(right_check(move1, move2-1)){
                    
                    return true;                
                }
            }
            if(move2+1 < getSizeOfBoard() && (*(next(it,1))).getCPosition() == user1){
                if(right_check(move1, move2+1)){
                    
                    return true;
                }   
            }
            if(move1+1 < getSizeOfBoard() && move2-1 >= 0 && (*(next(it,size-1))).getCPosition() == user1){
                if(right_check(move1+1, move2-1)){
                    
                    return true;
                }
            }
            if(move1+1 < getSizeOfBoard() && (*(next(it,size))).getCPosition() == user1){
                if(right_check(move1+1, move2)){
                    
                    return true; 
                }
            }                                                               
     
        }
    }
    
    (*it).setCPosition(temp);
    return false;
}
bool HexVector::top_check(const int &move1 ,const int &move2 ){
    vector<Cell>::iterator it = hexCells.begin();
    for(int i=0; i<(move1*getSizeOfBoard())+move2 ; i++)
        it++;
    int size = getSizeOfBoard();
    position temp =  (*it).getCPosition();
    if(temp == user2){
        (*it).setCPosition(win2);
        if(temp == user2 && move1 == getSizeOfBoard()-1){
            return true;
        }
        else{
            if(move1-1 >= 0 && (*(prev(it,size))).getCPosition() == user2){
                if(top_check(move1-1, move2)){
                    return true;
                }
            }
            if(move1-1 >= 0 && move2+1 < getSizeOfBoard() && (*(prev(it,size-1))).getCPosition() == user2){
                if(top_check(move1-1, move2+1)){
                    return true;
                }
            }
            if(move2-1 >= 0 && (*(prev(it,1))).getCPosition() == user2){
                if(top_check(move1, move2-1)){
                    return true;
                }
            }
        
            if(move2+1 < getSizeOfBoard() && (*(next(it,1))).getCPosition() == user2){
                if(top_check(move1, move2+1)){
                    return true;
                }
            }        
            if(move1+1 < getSizeOfBoard() && move2-1 >= 0 && (*(prev(it,size-1))).getCPosition() == user2 ){
                if(top_check(move1+1, move2-1)){
                    return true;
                }
            }
            if(move1+1 < getSizeOfBoard() && (*(next(it,1))).getCPosition() == user2){
                if(top_check(move1+1, move2)){
                    return true; 
                }
            }
        }
        
    }
    (*it).setCPosition(temp);
    return false;
}
bool HexVector::isEnd(int move1 = 0,int move2 = 0){
    
    if(getRound()%2 == 1){
        for(auto i=0 ; i<getSizeOfBoard() ; i++){
            if(right_check(move1, move2)){
                return true;
            }
            move1++;
        }
    }
    else{
        for(auto i=0 ; i<getSizeOfBoard(); i++){
            if(top_check(move1, move2)){
                return true;
            }
            move2++;
        }
    }
    return false;
        
}



void HexVector::print(){
    cout << " " ;
    auto it = this->hexCells.begin();
    for(auto i=0 ; i<this->getSizeOfBoard() ; i++){
        cout << static_cast<char>(i+65) << " " ;
    }
    cout << endl;
    for(int i = 0 ; i<getSizeOfBoard() ; i++){
        cout << i+1 ;
        for(auto k=0 ; k<i ; k++){
            cout << " ";
        }
        for(int j = 0; j <getSizeOfBoard() ; j++){
            cout << (*it).get_table_character() << " ";
            it++;
        }
        cout << endl;
    }
    
}
AbstractHex::Cell HexVector::lastMove()const{
    return (lastCells.back());
}
void HexVector::reset(){
    
    hexCells.clear();
    lastCells.clear();
    
    setTable();
    
}
int HexVector::numberOfMoves()const{
    return lastCells.size();
}
void HexVector::writeToFile(const string& row){
    ofstream myfile (row);
    
    if(myfile.is_open()){
        int typePlay;
        char character;
        
        myfile << this->getSizeOfBoard() << endl;
        myfile << this->getRound() << endl;
        switch(this->getPlayType()){
            case ifempty:
                typePlay = 0;
                break;
            case user:
                typePlay = 1;
                break;
            case computer:
                typePlay = 2;
                break;
        }
        myfile << typePlay<< endl;
        

        auto it= this->hexCells.begin();
        for(int i=0; i <getSizeOfBoard(); i++){
            for(int j=0 ; j<getSizeOfBoard() ; j++){
            
                switch((*it).getCPosition()){
                    case user1:
                        character = 'x';
                        break;
                    case user2:
                        character = 'o';
                        break;
                    case emptyCell:
                        character = '.';
                        break;
                    case win1:
                    case win2:
                    break;
                }
                it++;
                myfile << character;
            }
            myfile << endl;
        }
        
    }
    else{
        cerr << "unable to open file" << endl;
    }        
     myfile.close();
}
void HexVector::readFromFile(const string& row){
    ifstream myfile(row);
    if(myfile.is_open()){
        int typePlay ;
        char character;
        int size;
        myfile >> size ;
        this->setSizeOfBoard(size);
        this->setTable();
        int rou;
        myfile >> rou;
        this->setRound(rou);
        myfile >> typePlay;
        switch(typePlay){
        case 0:
                this->setPlayType(ifempty);
                break;
            case 1:
                this->setPlayType(user);
                break;
            case 2:
                this->setPlayType(computer);
                break;
        }
        auto it= this->hexCells.begin();
        while(it != this->hexCells.end()){
            myfile >> character;
            switch(character){
                case 'x':
                    (*it).setCPosition(user1);
                    break;
                case 'o':
                    (*it).setCPosition(user2);
                    break;
                case '.':
                    (*it).setCPosition(emptyCell);
                    break;
                case win1:
                case win2:
                break;
            }
                it++;
        }
        
    }
    else{
        cerr << "Unable to open file" << endl;
        exit(0);
    }
}



bool HexVector::operator==(AbstractHex& otherObject)const{
    
    if(getSizeOfBoard() != otherObject.getSizeOfBoard()){
        return false;
    }
    
    for(int i=0 ; i<getSizeOfBoard() ; i++){
        for(int j=0 ; j<getSizeOfBoard() ; j++){
            if((*this)(i,j) == (otherObject)(i,j)){
                return false;
            }
        }
    }
    
    
    return true;
}

AbstractHex::Cell HexVector::play(){
       
        //vector<Cell>::iterator tempIt = lastCells.begin();
        
        int move1 = lastCells.back().getPRow();
        int move2 = lastCells.back().getPColn();
        auto it = hexCells.begin();
        for(int i=0 ; i < (move1*getSizeOfBoard())+move2 ;i++){
            it++;
        }
        cout << (*it).getCPosition() << endl; 
        
        if(move2+1 < getSizeOfBoard() && (*next(it,1)).getCPosition() == emptyCell){
            
            return Cell(move2+1, move1,  user2);
        } 
        else if(move1-1 >= 0 && move2+1 < getSizeOfBoard() && (*(prev(it,(move2+1-(getSizeOfBoard()*move1))))).getCPosition() == emptyCell){
            
            return Cell(move2+1, move1-1, user2);
        }
        else if(move1+1 < getSizeOfBoard() && (*next(it,getSizeOfBoard())).getCPosition() == emptyCell){
           
            return Cell( move2, move1+1, user2);
        }
        else if(move1+1 < getSizeOfBoard() && move2-1 >= 0 && (*next(it,(-(getSizeOfBoard()*move1)+move2))).getCPosition() == emptyCell){
            
            return Cell(move2-1, move1+1,  user2);
        }
        else if(move1-1 >= 0 && (*prev(it,getSizeOfBoard())).getCPosition() == emptyCell){
           
            return Cell(move2, move1-1, user2);
        }
        else if(move2-1 >= 0 && (*prev(it,1)).getCPosition() == emptyCell){
            
            return Cell( move2-1, move1, user2);
         }
         srand (time(NULL));
         move1 = rand() % getSizeOfBoard() ;
         srand (time(NULL));
         move2 = rand() % getSizeOfBoard() ;
         return play(move1,move2);
         
         
   }
AbstractHex::Cell HexVector::play(int move1, int move2){
    position cp;
    if(getRound()%2 == 1){cp  = user1;} 
    else{cp = user2;}
    
    vector<Cell>::iterator it = hexCells.begin();
    it += ((move1*getSizeOfBoard())+move2);
    if((*it).getCPosition() == emptyCell){
       
        return Cell(move2, move1, cp);
    }
    else{ 
            round--;
            cerr << "Current possition is not available" << endl;
            Cell temp = Cell(move2,move1,(*it).getCPosition());
            return temp;
    }

}
AbstractHex::Cell HexVector::operator()(int move1, int move2)const{
    return Cell(hexCells.at((move1*getSizeOfBoard())+move2-1).getCPosition());
}

void HexVector::setSize(){
    int size;
    if(getSizeOfBoard() == 0){
        cout << "Which size do you want to play?(Size of board can be between 6 to 26!!\n";
        
        cin >> size;
        setSizeOfBoard(size);
    }
    else{
        
    }
    
    if(getSizeOfBoard() < 6  || getSizeOfBoard() > 26){
        cerr << "The game size is not valid!!!" << endl;
        setSize();
    }
    
}

void HexVector::playGame(){
    setSize();
    if(round == 0){
        setTable();
    }
    setType();
    print();
    string row,coln;//takes the input from user
    cout << "THE GAME BEGINS" << endl;
    int move1, move2;//finds the location as a integer datatype
    cin.ignore();
    while(isEnd() != true ){
        round++;
        if(round%2 == 1){
            cout << "USER1 MOVE:";
        
            getline(cin,coln,' ');
            getline(cin,row);
             
            if(coln == "LOAD"){// Load's part for user1
                readFromFile(row);
                continue;
            }
            
            else if(coln == "SAVE"){//Save's part for user1
                writeToFile(row);
                round--;
                continue;
            }
            else if(coln =="EXIT"){// Backs to main menu 
                    round--;
                    break;
            }
          
            char charColn = coln[0];
            
            move1 = stoi(row) - 1;
            move2 = static_cast<int>(charColn-65);
            auto it = hexCells.begin();
            for(int i=0 ; i < (move1*getSizeOfBoard())+move2 ;i++){
                it++;
            }
            Cell temp = play(move1, move2);
            auto it1 = hexCells.begin();
            for(int i=0 ; i < (temp.getPRow()*getSizeOfBoard())+temp.getPColn() ;i++){
                it1++;
            }
            *it1 = temp;
            lastCells.push_back(temp);
            print();
        }
         else{//User2's part            
            if(getPlayType() == user){
                cout << "USER2 MOVE:";
                getline(cin,coln,' ');
                getline(cin,row);       
                if(coln == "LOAD"){// Load's part for user2
                    readFromFile(row);
                    continue;
                }
                else if(coln == "SAVE"){// Save's part for user2
                    writeToFile(row);
                    round--;
                    continue;
                }
                else if(coln =="EXIT"){
                    round--;
                    break;
                }
                char charColn = coln[0];
                move1 = stoi(row) - 1;
                move2 = static_cast<int>(charColn-65);
                
                auto it = hexCells.begin();
                for(int i=0 ; i < (move1*getSizeOfBoard())+move2 ;i++){
                    it++;
                }
                Cell temp = play(move1, move2);
                auto it1 = hexCells.begin();
                for(int i=0 ; i < (temp.getPRow()*getSizeOfBoard())+temp.getPColn() ;i++){
                    it1++;
                }
                *it1 = temp;
                lastCells.push_back(temp);
                print();
        }//Computer's part
            else if(getPlayType() == computer){
                cout << coln << endl;
                cout << "COMPUTER MOVE:" << endl;
                auto it = hexCells.begin();
                for(int i=0 ; i < (move1*getSizeOfBoard())+move2 ;i++){
                    it++;
                }
                cout << (*it).getCPosition() << endl;
                Cell temp = play();
                
                lastCells.push_back(temp);
                auto it1 = hexCells.begin();
                for(int i=0 ; i < (temp.getPRow()*getSizeOfBoard()+temp.getPColn()) ;i++){
                    it1++;
                }
                *it1 = temp; 
                print();
            }
            
            else{
                cerr << "Wrong comment for choice" << endl;
                exit(0);
            }
        }
       
}
    if(coln =="EXIT" ){
        
    }
    else if(round%2 == 1){
        cout << "USER1 WINS" << endl;
        print();
        round = 0;
    }
    else{
        if(getPlayType() == user){
            cout << "USER2 WINS" << endl;
            print();
            round = 0;
        }
        else{
            cout << "COMPUTER WINS" << endl;
            print();
            round = 0;
        }
    }
}

void HexVector::setTable(){
    int size = getSizeOfBoard()*getSizeOfBoard();
    for(int i=0 ; i < size ; i++){
        hexCells.push_back(Cell(emptyCell));
    }
    
}
void HexVector::setType(){
     
        int choice;
        if(getPlayType() == ifempty){
            cout << "Do you want to play against user or computer? "
                    << "1-)User" 
                    << "2-)Computer" << endl;
            cin >> choice;
            switch(choice){
            case 1:
                setPlayType(user);
                break;
            case 2:
                setPlayType(computer);
                break;
            default:
                cerr << "Invalid play type" << endl;
                setType();
                cin.ignore();
        }
        
                
        }
}  


