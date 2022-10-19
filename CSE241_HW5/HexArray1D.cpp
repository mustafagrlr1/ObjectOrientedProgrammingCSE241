
#include <iostream>
#include <iterator>
#include <vector>
#include <fstream>
#include <time.h>
#include <string>
#include "AbstractHex.h"
#include "HexArray1D.h"
#include <time.h>

using namespace std;

HexArray1D::HexArray1D(const HexArray1D& rhs){
    
    
        setSizeOfBoard(rhs.getSizeOfBoard());
        int size = getSizeOfBoard()*getSizeOfBoard();
        
        hexCells = (Cell*)(malloc(sizeof(Cell)*size));
        setRound(rhs.getRound());
        setType(rhs.getPlayType());
        auto it = rhs.lastCells.begin();
        while(it != rhs.lastCells.end()){
            lastCells.push_back((*it));
            it++;
        }
    
    
}
HexArray1D& HexArray1D::operator=(const HexArray1D& rhs){
    setSizeOfBoard(rhs.getSizeOfBoard());
    int size = getSizeOfBoard()*getSizeOfBoard();
    delete[] hexCells;
    hexCells = (Cell*)(malloc(sizeof(Cell)*size));
    setRound(rhs.getRound());
    setType(rhs.getPlayType());
    auto it = rhs.lastCells.begin();
    while(it != rhs.lastCells.end()){
        lastCells.push_back(*it);
        it++;
    }
    return *this;
}
void HexArray1D::setSize(){
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

void HexArray1D::setTable(){
    int size = getSizeOfBoard()*getSizeOfBoard();
    hexCells = (Cell*)(malloc(sizeof(Cell)*size));
    for(int i=0 ; i < size ; i++){
        hexCells[i].setCPosition(emptyCell);
    }
}
void HexArray1D::setType(against type = ifempty){
    
    int choice;
    if(getPlayType() == ifempty){
        cout << "Do you want to play against user or computer? "
                << "1-)User" 
                << "2-)Computer" << endl;
        cin >> choice;
        switch(choice){
        case 1:
            setType(user);
            break;
        case 2:
            setType(computer);
            break;
        default:
            cerr << "Invalid play type" << endl;
            setType();
        }
    }
}  
bool HexArray1D::right_check(const int &move1,const int &move2){
    
    position temp =  hexCells[(move1*getSizeOfBoard())+move2].getCPosition();
    if(temp == user1){
        hexCells[(move1*getSizeOfBoard())+move2].setCPosition(win1);
        if(temp == user1 && move2 == getSizeOfBoard()-1){
            return true;
        }
        else{
            if(move1-1 >= 0 && hexCells[((move1-1)*getSizeOfBoard())+move2].getCPosition() == user1){
                if(right_check(move1-1, move2)){
                    hexCells[(move1*getSizeOfBoard())+move2].setCPosition(win1);
                    return true;
                }            
            }
            if(move1-1 >= 0 && move2+1 < getSizeOfBoard() && hexCells[((move1-1)*getSizeOfBoard())+move2+1].getCPosition() == user1){
                if(right_check(move1-1, move2+1)){                  
                    hexCells[(move1*getSizeOfBoard())+move2].setCPosition(win1);
                    return true;
                }
            }
            if(move2-1 >= 0 && hexCells[(move1*getSizeOfBoard())+move2-1].getCPosition() == user1){
                if(right_check(move1, move2-1)){
                    hexCells[(move1*getSizeOfBoard())+move2].setCPosition(win1);
                    return true;
                }
            }
            if(move2+1 < getSizeOfBoard() && hexCells[(move1*getSizeOfBoard())+move2+1].getCPosition() == user1){
                if(right_check(move1, move2+1)){
                    hexCells[(move1*getSizeOfBoard())+move2].setCPosition(win1);
                    return true;
                }
            }
            if(move1+1 < getSizeOfBoard() && move2-1 >= 0 && hexCells[((move1+1)*getSizeOfBoard())+move2-1].getCPosition() == user1){
                if(right_check(move1+1, move2-1)){            
                    hexCells[(move1*getSizeOfBoard())+move2].setCPosition(win1);
                    return true;
                }
            }
            if(move1+1 < getSizeOfBoard() && hexCells[((move1+1)*getSizeOfBoard())+move2].getCPosition() == user1){
                if(right_check(move1+1, move2)){
                    hexCells[(move1*getSizeOfBoard())+move2].setCPosition(win1);
                    return true; 
                }
        }                                                               
     
}
}
    
    hexCells[(move1*getSizeOfBoard())+move2].setCPosition(temp);
    return false;
}
bool HexArray1D::operator==(AbstractHex& otherObject)const{
    
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
bool HexArray1D::top_check(const int &move1 ,const int &move2 ){
    position temp = hexCells[(move1*getSizeOfBoard())+move2].getCPosition();
    
    if(temp == user2){
        hexCells[(move1*getSizeOfBoard())+move2].setCPosition(win2);
        if(temp == user2 && move1 == getSizeOfBoard()-1){
            return true;
        }
        else{
            if(move1-1 >= 0 && hexCells[((move1-1)*getSizeOfBoard())+move2].getCPosition() == user2){
                if(top_check(move1-1, move2)){
                    return true;
                }
            }
            if(move1-1 >= 0 && move2+1 < getSizeOfBoard() && hexCells[((move1-1)*getSizeOfBoard())+move2+1].getCPosition() == user2){
                if(top_check(move1-1, move2+1)){
                    return true;
                }
            }
            if(move2 >= 0 && hexCells[(move1*getSizeOfBoard())+move2-1].getCPosition() == user2){
                if(top_check(move1, move2-1)){
                    return true;
                }                    
            }
        
            if(move2+1 < getSizeOfBoard() && hexCells[(move1*getSizeOfBoard())+move2+1].getCPosition() == user2){
                if(top_check(move1, move2+1)){
                    return true;
                }
            }        
            if(move1+1 < getSizeOfBoard() && move2-1 >= 0 && hexCells[((move1+1)*getSizeOfBoard())+move2-1].getCPosition() == user2 ){
                if(top_check(move1+1, move2-1)){
                    return true;
                }
            }
            if(move1+1 < getSizeOfBoard() && hexCells[((move1+1)*getSizeOfBoard())+move2].getCPosition() == user2){
                if(top_check(move1+1, move2)){
                    return true; 
                }
            }
        }
        
    }
    hexCells[(move1*getSizeOfBoard())+move2].setCPosition(temp);

    return false;
    
    
}
bool HexArray1D::isEnd(int move1 = 0,int move2 = 0){
    
    if(round%2 == 1){
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

void HexArray1D::readFromFile(const string& row){
    ifstream myfile(row);
    if(myfile.is_open()){
        int typePlay ;
        char character;
        int size;
        int rou;
        myfile >> size;
        this->setSizeOfBoard(size);
        this->setTable();
        myfile >> rou;
        this->setRound(rou);
        myfile >> typePlay;
        switch(typePlay){
        case 0:
                this->setType(ifempty);
                break;
            case 1:
                this->setType(user);
                break;
            case 2:
                this->setType(computer);
                break;
        }
        size = getSizeOfBoard()*getSizeOfBoard();
        for(int i=0; i< size ; i++){
            myfile >> character;
            switch(character){
                case 'x':
                    hexCells[i].setCPosition(user1);
                    break;
                case 'o':
                    hexCells[i].setCPosition(user2);
                    break;
                case '.':
                    hexCells[i].setCPosition(emptyCell);
                    break;
                case win1:
                case win2:
                break;
            }
        }
        this->round--;
    }
    else{
        cerr << "Unable to open file" << endl;
        exit(0);
    }
}
void HexArray1D::writeToFile(const string& row){
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
        

        for(auto i=0 ; i<this->getSizeOfBoard() ; i++){
            
            for(auto j=0 ; j<this->getSizeOfBoard() ; j++){
                switch(this->hexCells[(i*getSizeOfBoard())+j].getCPosition()){
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
void HexArray1D::print(){
    cout << " " ;
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
            cout << hexCells[(i*getSizeOfBoard()+j)].get_table_character() << " ";
        }
        cout << endl;
    }
    
}
void HexArray1D::reset(){    
    delete[] hexCells;
    setTable();

    while(!lastCells.empty()){ 
        lastCells.pop_back();
    }
    
}
AbstractHex::Cell HexArray1D::play(){
       
        //vector<Cell>::iterator tempIt = lastCells.begin();
        
        int move1 = lastCells.back().getPRow();
        int move2 = lastCells.back().getPColn();
        
        if(move2+1 < getSizeOfBoard() && hexCells[move1*getSizeOfBoard()+move2+1].getCPosition() == emptyCell){
            
            return Cell(move2+1, move1,  user2);
        } 
        else if(move1-1 >= 0 && move2+1 < getSizeOfBoard() && hexCells[(move1-1)*getSizeOfBoard()+move2].getCPosition() == emptyCell){
            
            return Cell(move2+1, move1-1, user2);
        }
        else if(move1+1 < getSizeOfBoard() && hexCells[(move1+1)*getSizeOfBoard()+move2].getCPosition() == emptyCell){
           
            return Cell( move2, move1+1, user2);
        }
        else if(move1+1 < getSizeOfBoard() && move2-1 >= 0 && hexCells[(move1+1)*getSizeOfBoard()+move2-1].getCPosition() == emptyCell){
            
            return Cell(move2-1, move1+1,  user2);
        }
        else if(move1-1 >= 0 && hexCells[(move1-1)*getSizeOfBoard()+move2].getCPosition() == emptyCell){
           
            return Cell(move2, move1-1, user2);
        }
        else if(move2-1 >= 0 && hexCells[move1*getSizeOfBoard()+move2-1].getCPosition() == emptyCell){
            
            return Cell( move2-1, move1, user2);
         }
         srand (time(NULL));
         move1 = rand() % getSizeOfBoard() ;
         srand (time(NULL));
         move2 = rand() % getSizeOfBoard() ;
         return play(move1,move2);
         
         
   }
AbstractHex::Cell HexArray1D::play(int move1, int move2){
    position cp;
    if(round%2 == 1){cp  = user1;} 
    else{cp = user2;}
    
    if((hexCells[move1*getSizeOfBoard()+move2].getCPosition()) == emptyCell){
       
        return Cell(move2, move1, cp);
    }
    else{ 
            round--;
            cerr << "Current possition is not available" << endl;
            return Cell(move2,move1,hexCells[move1*getSizeOfBoard()+move2].getCPosition());
    }

}
AbstractHex::Cell HexArray1D::operator()(int move1, int move2)const{
    return hexCells[move1*getSizeOfBoard()+move2-1];
}
AbstractHex::Cell HexArray1D::lastMove()const{
    return (lastCells.back());
}
int HexArray1D::numberOfMoves()const{
    return lastCells.size();
}

void HexArray1D::playGame(){
    setSize();
    
    if(round == 0){
        setTable();
    }
    setType();
    
    string row,coln;//takes the input from user
    cout << "THE GAME BEGINS" << endl;
    int move1,move2;
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
            Cell temp = play(move1, move2);
            int r = temp.getPRow();
            int c = temp.getPColn();
            hexCells[(r*getSizeOfBoard())+c] = temp;
            lastCells.push_back(Cell(r,c,user1));
            print();
        }
         else{//User2's part            
            if(getPlayType() == user){
                cout << "USER2 MOVE:";
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
            Cell temp = play(move1, move2);
            int r = temp.getPRow();
            int c = temp.getPColn();
            hexCells[(r*getSizeOfBoard())+c] = temp;
            lastCells.push_back(Cell(r,c,user2));
            print();
        }//Computer's part
            else if(getPlayType() == computer){
                cout << coln << endl;
                cout << "COMPUTER MOVE:" << endl;
                Cell temp = play();
                int r = temp.getPRow();
                int c = temp.getPColn();
                hexCells[(r*getSizeOfBoard())+c] = temp;
                print();
                lastCells.push_back(Cell(r,c,user2));
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

