#include "hex.h"
#include <iostream>
#include <vector>
#include <string.h>
#include <fstream>



void Hex::Cell::setPColn(char c){pColn = c;}

void Hex::Cell::setPRow(char r){pRow = r;}

void Hex::Cell::setCPosition(position cp){cPosition = cp;}

char Hex::Cell::get_table_character(){
            if(getCPosition() == win1){return 'X';}
            else if(getCPosition() == win2){return 'O';}
            else if(getCPosition() == user1){return 'x';}
            else if(getCPosition() == user2){return 'o';}
            else{ return '.';}
                
}

bool Hex::right_check(int move1, int move2){
    
    position temp =  hexCells[move1][move2].getCPosition();
    if(temp == user1){
        hexCells[move1][move2].setCPosition(win1);
        if(temp == user1 && move2 == getSizeOfBoard()-1){
            
            return true;
        }
        else{
            if(move1-1 >= 0 && hexCells[move1-1][move2].getCPosition() == user1){
                    if(right_check(move1-1, move2)){
                        
                        return true;
                    }
                
            }
            if(move1-1 >= 0 && move2+1 < getSizeOfBoard() && hexCells[move1-1][move2+1].getCPosition() == user1){
        
                    if(right_check(move1-1, move2+1)){
                      
                        return true;
                    }
            }
            if(move2-1 >= 0 && hexCells[move1][move2-1].getCPosition() == user1){
        
                    if(right_check(move1, move2-1)){
                    
                        return true;
                    }
            }
            if(move2+1 < getSizeOfBoard() && hexCells[move1][move2+1].getCPosition() == user1){
        
                    if(right_check(move1, move2+1)){
 
                        return true;
                    }
            }
            if(move1+1 < getSizeOfBoard() && move2-1 >= 0 && hexCells[move1+1][move2-1].getCPosition() == user1){
        
                    if(right_check(move1+1, move2-1)){
                
                        return true;
                    }
            }
            if(move1+1 <getSizeOfBoard() && hexCells[move1+1][move2].getCPosition() == user1){
        
                    if(right_check(move1+1, move2)){
                        
                        return true; 
                    }
        }
     
}
}
 hexCells[move1][move2].setCPosition(temp);
    return false;
}



bool Hex::top_check(int move1 , int move2 ){
    position temp = hexCells[move1][move2].getCPosition();
    
    if(temp == user2){
        hexCells[move1][move2].setCPosition(win2);
        if(temp == user2 && move1 == getSizeOfBoard()-1){
            
            return true;
        }
        else{
            if(move1-1 >= 0 && hexCells[move1-1][move2].getCPosition() == user2)
                    if(top_check(move1-1, move2)){
                       hexCells[move1][move2].setCPosition(win2);
                        return true;
                    }
            if(move1-1 >= 0 && move2+1 < getSizeOfBoard() && hexCells[move1-1][move2+1].getCPosition() == user2)
        
                    if(top_check(move1-1, move2+1)){
                        hexCells[move1][move2].setCPosition(win2);
                        return true;
                    }
        
            if(move2 >= 0 && hexCells[move1][move2-1].getCPosition() == user2)
        
                    if(top_check(move1, move2-1)){
                      hexCells[move1][move2].setCPosition(win2);
                        return true;
                    }
        
            if(move2+1 < getSizeOfBoard() && hexCells[move1][move2+1].getCPosition() == user2)
        
                    if(top_check(move1, move2+1)){
                        hexCells[move1][move2].setCPosition(win2);
                        return true;
                    }
        
            if(move1+1 < getSizeOfBoard() && move2-1 >= 0 && hexCells[move1+1][move2-1].getCPosition() == user2 )
        
                    if(top_check(move1+1, move2-1)){
                        hexCells[move1][move2].setCPosition(win2);
                        return true;
                    }
        
            if(move1+1 < getSizeOfBoard() && hexCells[move1+1][move2].getCPosition() == user2)
        
                    if(top_check(move1+1, move2)){
                        hexCells[move1][move2].setCPosition(win2);
                        return true; 
                    }
        }
        
    }
        hexCells[move1][move2].setCPosition(temp);
        return false;
        
    
}


bool Hex::final_game(int move1 = 0,int move2 = 0){
    
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

void Hex::play(int move1, int move2){
    position cp;
    if(round%2 == 1){ cp  = user1;} 
    else{cp = user2;}
    
    if(hexCells[move1][move2].getCPosition() == emptyCell){
        hexCells[move1][move2].setCPosition(cp);
        count++;
    }
    else{
            round--;
            cerr << "Current possition is not available" << endl;
            
    }

}


void Hex::play(){
        
        int move1 = lastMove[0];
        int move2 = lastMove[1];
        
        if(move2+1 < getSizeOfBoard() && hexCells[move1][move2+1].getCPosition() == emptyCell){
            hexCells[move1][move2+1].setCPosition(user2);
            count++;
        } 
        else if(move1-1 >= 0 && move2+1 < getSizeOfBoard() && hexCells[move1-1][move2+1].getCPosition() == emptyCell){
            
            hexCells[move1-1][move2+1].setCPosition(user2);
            count++;
        }
        else if(move1+1 < getSizeOfBoard() && hexCells[move1+1][move2].getCPosition() == emptyCell){
           hexCells[move1+1][move2].setCPosition(user2);
           count++;
        }
        else if(move1+1 < getSizeOfBoard() && move2-1 >= 0 && hexCells[move1+1][move2-1].getCPosition() == emptyCell){
            hexCells[move1+1][move2-1].setCPosition(user2);
            count++;
        }
        else if(move1-1 >= 0 && hexCells[move1-1][move2].getCPosition() == emptyCell){
            hexCells[move1-1][move2-1].setCPosition(user2);
            count++;
        }
        else if(move2-1 >= 0 && hexCells[move1][move2-1].getCPosition() == emptyCell){
            hexCells[move1][move2-1].setCPosition(user2);
            count++;
        }
   }
   

void Hex::playGame(){
    setSizeOfBoard();

    if(round == 0){
        setTable();
    }
    setType();
    
    string row,coln;//takes the input from user
    
    int move1, move2;//finds the location as a integer datatype
    cin.ignore();
    while(final_game() != true ){
    round++;
//User1's part        
        if(round%2 == 1){
            cout << "USER1 MOVE:";
        
            getline(cin,coln,' ');
            getline(cin,row);
             
            if(coln == "LOAD"){// Load's part for user1 
                load_game(row);
                
                continue;
            }
            else if(coln == "SAVE"){//Save's part for user1
                save_game(row);
                
            }
            else if(coln =="EXIT"){
                    round--;
                    break;
            }
            char charColn = coln[0];
    
            move1 = stoi(row) - 1;
            move2 = static_cast<int>(charColn-65);
            lastMove[0] = move1;
            lastMove[1] = move2;
            play(move1,move2);
            displayBoard();
            
        }
        else{
//User2's part            
            if(getPlayType() == user){
                cout << "USER2 MOVE:";
                getline(cin,coln,' ');
               
                
                //cin.ignore();
                getline(cin,row);       
                if(coln == "LOAD"){// Load's part for user1 
                    load_game(row);
                    continue;
                }
                else if(coln == "SAVE"){// Save's part for user1 
                    save_game(row);
                    
                }
                else if(coln =="EXIT"){
                    round--;
                    break;
                }
            
         
                char charColn = coln[0];
                move1 = stoi(row) -1;
                move2 = static_cast<int>(charColn-65);
                
                play(move1,move2);
                displayBoard();
                
            }
//Computer's part
            else if(getPlayType() == computer){
                cout << "COMPUTER MOVE:" << endl;
                play();
                displayBoard();
                
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
        displayBoard();
        round = 0;
    }
    else{
        if(getPlayType() == user){
            cout << "USER2 WINS" << endl;
            displayBoard();
            round = 0;
        }
        else{
            cout << "COMPUTER WINS" << endl;
            displayBoard();
            round = 0;
        }
    }
}
void Hex::load_game(const string &row){
        
        ifstream file;
        int typePlay ;
        file.open(row);
        
        char character ;
        if(file.is_open()){
            file >> sizeOfBoard;
            file >> round;
            file >> typePlay;
            switch(typePlay){
            case 0:
                    playType = ifempty;
                    break;
                case 1:
                    playType = user;
                    break;
                case 2:
                    playType = computer;
                    break;
            }
        
             for(auto i=0 ; i<sizeOfBoard ; i++){
                for(auto j=0 ; j<sizeOfBoard ; j++){
                    
                    file >> character;
                    switch(character){
                            case 'x':
                                hexCells[i][j].setCPosition(user1);
                                break;
                            case 'o':
                                hexCells[i][j].setCPosition(user2);
                                break;
                            case '.':
                                hexCells[i][j].setCPosition(emptyCell);
                                break;
                            case win1:
                            case win2:
                            break;
                    }
                    
                    
                 
                }
            }
              
                file.close();
                round--;
        }   
        else cerr << "Unable to open file" ;
}
void Hex::save_game(const string &row){
    ofstream myfile (row);
    int typePlay;
    char character;
    if(myfile.is_open()){
        myfile << sizeOfBoard << endl;
        myfile << round << endl;
        switch(playType){
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
        
    
        for(auto i=0 ; i<sizeOfBoard ; i++){
            
            for(auto j=0 ; j<sizeOfBoard ; j++){
                switch(hexCells[i][j].getCPosition()){
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
                    myfile<< character;
            }
            myfile << endl;
        }
        
        myfile.close();
    }
    else{
        cerr << "unable to open file" << endl;
    }        
}
void Hex::setTable(){
    
    hexCells.resize(getSizeOfBoard());
    for(int j=0 ; j < getSizeOfBoard() ; j++){
            hexCells[j].resize(getSizeOfBoard());
        }
    for(int i = 0 ; i < getSizeOfBoard() ; i++){
        for(int j=0 ; j < getSizeOfBoard() ; j++){
            hexCells[i][j].setCPosition(emptyCell);
        }
    }
}
void Hex::setType(){
     
        int choice;
        if(playType == ifempty){
            cout << "Do you want to play against user or computer? "
                    << "1-)User" 
                    << "2-)Computer" << endl;
            cin >> choice;

            switch(choice){
            case 1:
                playType = user;
                break;
            case 2:
                playType = computer;
                break;
            default:
                cerr << "Invalid play type" << endl;
                setType();
        }
        
                
        }
}  
void Hex::setSizeOfBoard( ){
        if(getSizeOfBoard() == 0){
            cout << "Which size do you want to play?(Size of board can be between 6 to 26!!\n";
                    
            cin >> sizeOfBoard;
            
        }
        
        if(sizeOfBoard < 6  || sizeOfBoard > 26){
            cerr << "The game size is not valid!!!" << endl;
            setSizeOfBoard();
        }
        
}
void Hex::displayBoard() {
     
    
    cout << " " ;
    for(auto i=0 ; i<getSizeOfBoard() ; i++){
        cout << static_cast<char>(i+65) << " " ;
    }
    cout << endl;
    for(auto i=0 ; i<getSizeOfBoard() ; i++){
    
        for(auto k=0 ; k<i ; k++){
            cout << " " ;
        }
        
        cout << i+1  << " ";
        
        for(auto j=0 ; j<getSizeOfBoard() ; j++){
            cout << hexCells[i][j].get_table_character() << " "  ;
        }
        cout << endl;
    } 
    
}
bool Hex::compare_cells(Hex otherObject){
    
    int object1count = 0, object2count = 0;
    
    for( int i=0 ; i<this->getSizeOfBoard() ; i++){
        for( int j=0 ; j<this->getSizeOfBoard() ; j++){
            if(this->hexCells[i][j].getCPosition() != emptyCell){
                object1count++;
            } 
        }
    }
     
    for( int i=0 ; i<otherObject.getSizeOfBoard() ; i++){
        for( int j=0 ; j<otherObject.getSizeOfBoard() ; j++){
            if(otherObject.hexCells[i][j].getCPosition() != emptyCell){
                object2count++;
            } 
        }
    }
    
    if(object1count > object2count){
        return true;
    }
    return false;
}
