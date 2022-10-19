#include "Hex.h"
#include <iostream>
#include <cstdlib>
#include <time.h>
void Cell::setPColn(const char &c){pColn = c;}

void Cell::setPRow(const char &r){pRow = r;}

void Cell::setCPosition(const position &cp){cPosition = cp;}

char Cell::get_table_character(){
            if(getCPosition() == win1){return 'X';}
            else if(getCPosition() == win2){return 'O';}
            else if(getCPosition() == user1){return 'x';}
            else if(getCPosition() == user2){return 'o';}
            else{ return '.';}
                
}

bool Hex::right_check(const int &move1,const int &move2){
    
    position temp =  hexCells[move1][move2].getCPosition();
    if(temp == user1){
        hexCells[move1][move2].setCPosition(win1);
        if(temp == user1 && move2 == getSizeOfBoard()-1){
            scoreUser1++;
            return true;
        }
        else{
            if(move1-1 >= 0 && hexCells[move1-1][move2].getCPosition() == user1){
                    scoreUser1++;
                    if(right_check(move1-1, move2)){
                        
                        return true;
                    }
                
            }
            if(move1-1 >= 0 && move2+1 < getSizeOfBoard() && hexCells[move1-1][move2+1].getCPosition() == user1){
                    scoreUser1++;
                    if(right_check(move1-1, move2+1)){
                      
                        return true;
                    }
            }
            if(move2-1 >= 0 && hexCells[move1][move2-1].getCPosition() == user1){
                    scoreUser1++;
                    if(right_check(move1, move2-1)){
                    
                        return true;
                    }
            }
            if(move2+1 < getSizeOfBoard() && hexCells[move1][move2+1].getCPosition() == user1){
                    scoreUser1++;
                    if(right_check(move1, move2+1)){
 
                        return true;
                    }
            }
            if(move1+1 < getSizeOfBoard() && move2-1 >= 0 && hexCells[move1+1][move2-1].getCPosition() == user1){
                    scoreUser1++;
                    if(right_check(move1+1, move2-1)){
                
                        return true;
                    }
            }
            if(move1+1 < getSizeOfBoard() && hexCells[move1+1][move2].getCPosition() == user1){
                    scoreUser1++;
                    if(right_check(move1+1, move2)){
                        
                        return true; 
                    }
        }                                                               
     
}
}
    
 hexCells[move1][move2].setCPosition(temp);
    return false;
}
bool Hex::top_check(const int &move1 ,const int &move2 ){
    position temp = hexCells[move1][move2].getCPosition();
    
    if(temp == user2){
        hexCells[move1][move2].setCPosition(win2);
        if(temp == user2 && move1 == getSizeOfBoard()-1){
            scoreUser2++;
            return true;
        }
        else{
            if(move1-1 >= 0 && hexCells[move1-1][move2].getCPosition() == user2){
                    scoreUser2++;
                    if(top_check(move1-1, move2)){
                       hexCells[move1][move2].setCPosition(win2);
                        return true;
                    }
            }
            if(move1-1 >= 0 && move2+1 < getSizeOfBoard() && hexCells[move1-1][move2+1].getCPosition() == user2){
                    scoreUser2++;
                    if(top_check(move1-1, move2+1)){
                        hexCells[move1][move2].setCPosition(win2);
                        return true;
                    }
            }
            if(move2 >= 0 && hexCells[move1][move2-1].getCPosition() == user2){
                    scoreUser2++;
                    if(top_check(move1, move2-1)){
                      hexCells[move1][move2].setCPosition(win2);
                        return true;
                    }
                    
            }
        
            if(move2+1 < getSizeOfBoard() && hexCells[move1][move2+1].getCPosition() == user2){
                    scoreUser2++;
                    if(top_check(move1, move2+1)){
                        hexCells[move1][move2].setCPosition(win2);
                        return true;
                    }
            }        
            if(move1+1 < getSizeOfBoard() && move2-1 >= 0 && hexCells[move1+1][move2-1].getCPosition() == user2 ){
                    scoreUser2++;
                    if(top_check(move1+1, move2-1)){
                        hexCells[move1][move2].setCPosition(win2);
                        return true;
                    }
            }
            if(move1+1 < getSizeOfBoard() && hexCells[move1+1][move2].getCPosition() == user2){
                    scoreUser2++;
                    if(top_check(move1+1, move2)){
                        hexCells[move1][move2].setCPosition(win2);
                        return true; 
                    }
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

Cell Hex::play(int move1, int move2){
    position cp;
    if(round%2 == 1){cp  = user1;} 
    else{cp = user2;}
    
    if(hexCells[move1][move2].getCPosition() == emptyCell){
       count++;
        return Cell(move2, move1, cp);
    }
    else{ 
            round--;
            cerr << "Current possition is not available" << endl;
            return Cell();
    }

}
Cell Hex::play(){
        
        int move1 = lastMove[0];
        int move2 = lastMove[1];
        
        if(move2+1 < getSizeOfBoard() && hexCells[move1][move2+1].getCPosition() == emptyCell){
            count++;
            return Cell(move2+1, move1,  user2);
        } 
        else if(move1-1 >= 0 && move2+1 < getSizeOfBoard() && hexCells[move1-1][move2+1].getCPosition() == emptyCell){
            count++;
            return Cell(move2+1, move1-1, user2);
        }
        else if(move1+1 < getSizeOfBoard() && hexCells[move1+1][move2].getCPosition() == emptyCell){
           count++;
            return Cell( move2, move1+1, user2);
        }
        else if(move1+1 < getSizeOfBoard() && move2-1 >= 0 && hexCells[move1+1][move2-1].getCPosition() == emptyCell){
            count++;
            return Cell(move2-1, move1+1,  user2);
        }
        else if(move1-1 >= 0 && hexCells[move1-1][move2].getCPosition() == emptyCell){
            count++;
            return Cell(move2, move1-1, user2);
        }
        else if(move2-1 >= 0 && hexCells[move1][move2-1].getCPosition() == emptyCell){
            count++;
            return Cell( move2-1, move1, user2);
         }
         srand (time(NULL));
         move1 = rand() % getSizeOfBoard() ;
         srand (time(NULL));
         move2 = rand() % getSizeOfBoard() ;
         return play(move1,move2);
         
         
   }


 
int Hex::getScore(){

    int max1 = 0;
    int max2 = 0;
    
    for(int i = 0; i< getSizeOfBoard() ; i++){
        for(int j = 0 ; j < getSizeOfBoard() ; j++){
            if(hexCells[i][j] .getCPosition()== user1){
                scoreUser1 = 0;                                                                                
                if(i != getSizeOfBoard()-1){
                    right_check(i,j);
                }                                                                                                           
                else{
                    scoreUser1++;                                                                                                   
                }
                if(scoreUser1 > max1)
                    max1 = scoreUser1;
            }
            if(hexCells[i][j].getCPosition() == user2){
                scoreUser2 = 0;
                if(i != getSizeOfBoard()-1){
                    top_check(i,j);
                }else{
                    scoreUser2++;
                }
                if(scoreUser2  > max2){
                    max2 = scoreUser2;
                }
            }
            
        }
    }
    if(round <= 1){
        return 0;
    }
    else{
        if(max1 > max2){
            return 1;
        }
        else if(max2 > max1){
            return -1;
        }
        else{
            return 0;
        }
    }
}


ostream& operator<<(ostream &os, const Hex& other){
    os << " " ;
    for(auto i=0 ; i<other.getSizeOfBoard() ; i++){
        os << static_cast<char>(i+65) << " " ;
    }
    os << endl;
    for(auto i=0 ; i<other.getSizeOfBoard() ; i++){
    
        for(auto k=0 ; k<i ; k++){
            os << " " ;
        }
        
        os << i+1  << " ";
        
        for(auto j=0 ; j<other.getSizeOfBoard() ; j++){
            os << other.hexCells[i][j].get_table_character() << " "  ;
        }
        os << endl;
    } 
    return os;
}

void Hex::operator--(int){
    hexCells[getLastCellRow()][getLastCellColn()].setCPosition(emptyCell);
    deleteLastCell();
}
void Hex::operator--(){
    
    hexCells[getLastCellRow()][getLastCellColn()].setCPosition(emptyCell);
    deleteLastCell();
}
bool   Hex::operator==(const Hex &otherObject)const{
    
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

void Hex::playGame(){
    setSizeOfBoard();

    if(round == 0){
        setTable();
        fillLastCellBoard();
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
                    ifstream myfile(row);
                    sizeOfBoard = 0 ;
                    if(myfile.is_open()){
                        myfile >> (*this);
                    }
                    else{
                        cerr << "Unable to open file" << endl;
                        exit(0);
                    }
                    continue;
                }
            else if(coln == "UNDO"){
                
                cout << round << endl;
                if(round > 1){
                    (*this)--;
                    round -= 2;
                    cout << (*this);
                }
                else{
                    cerr << "Round : 0 => The play has not started yet" << endl;
                    round--;
                }
                continue;
            }
            else if(coln == "SAVE"){//Save's part for user1
                ofstream myfile (row);    
                if(myfile.is_open()){
                   myfile << (*this) ;
                    
                }
                else{
                    cerr << "unable to open file" << endl;
                }        
                 myfile.close();
                freeTable();           
                exit(0);
            }
            else if(coln =="EXIT"){// Backs to main menu 
                    round--;
                    break;
            }
            else if(coln =="SCORE"){
                    int score = getScore();
                    if(score == 1){
                        cout << "USER1 is winning!!\n"
                                << "Score" << scoreUser1-scoreUser2 << endl;
                    }
                    else if(score == -1){
                        cout << "USER2 is winning!!\n"
                                << "Score" << scoreUser2-scoreUser1 << endl;
                    }
                    else{
                        cout << "Equal game\n";
                    }
                    round--;
                    continue;
                }
            char charColn = coln[0];
            
            move1 = stoi(row) - 1;
            move2 = static_cast<int>(charColn-65);
            lastMove[0] = move1;
            lastMove[1] = move2;
            Cell temp = play(move1, move2);
            int r = temp.getPRow();
            int c = temp.getPColn();
            hexCells[r][c] = temp;
            setLastCell(r,c);
            cout << (*this);
            scoreUser1 = 0;
            scoreUser2 = 0;
            
        }
        else{
//User2's part            
            if(getPlayType() == user){
                cout << "USER2 MOVE:";
                getline(cin,coln,' ');
               
                
                //cin.ignore();
                getline(cin,row);       
                if(coln == "LOAD"){// Load's part for user2
                    ifstream myfile(row);
                    sizeOfBoard = 0 ;
                    if(myfile.is_open()){
                        myfile >> (*this);
                    }
                    else{
                        cerr << "Unable to open file" << endl;
                        exit(0);
                    }
                    continue;
                }
                else if(coln == "UNDO"){
                    cout << round << endl;
                    if(round > 1){
                        this->operator--(0);
                        round -= 2;
                        cout << (*this);
                        
                    }
                    else{
                        cerr << "Round : 0 => The play has not started yet" << endl;
                        round--;
                    }
                    continue;
                }
                else if(coln == "SAVE"){// Save's part for user2
                    ofstream myfile (row);    
                    if(myfile.is_open()){
                       myfile << (*this) ;
                        
                    }
                    else{
                        cerr << "unable to open file" << endl;
                    }        
                     myfile.close();
                    freeTable();           
                    exit(0);
                
                }
                else if(coln =="EXIT"){
                    round--;
                    break;
                }
                else if(coln =="SCORE"){
                    
                    if(getScore() == 1){
                        cout << "USER1 is winning!!\n"
                                << "Score" << scoreUser1-scoreUser2 << endl;
                    }
                    else if(getScore() == -1){
                        cout << "USER2 is winning!!\n"
                                << "Score" << scoreUser2-scoreUser1 << endl;
                    }
                    else{
                        cout << "Equal game\n";
                    }
                    round--;
                    continue;
                }
            
         
                char charColn = coln[0];
                move1 = stoi(row) - 1;
                move2 = static_cast<int>(charColn-65);
                Cell temp = play(move1, move2);
                int r = temp.getPRow();
                int c = temp.getPColn();
                hexCells[r][c] = temp;
                setLastCell(r,c);
                cout << (*this);
                scoreUser1 = 0;
                scoreUser2 = 0;
            }
//Computer's part
            else if(getPlayType() == computer){
                cout << coln << endl;
                cout << "COMPUTER MOVE:" << endl;
                if(coln == "UNDO"){
                     cout << round << endl;
                    if(round > 1){
                        (*this)--;
                        round -= 2;
                        cout << (*this);
                        
                    }
                    else{
                        cerr << "Round : 0 => The play has not started yet" << endl;
                        round--;
                    }
                    continue;
                }
                Cell temp = play();
                int r = temp.getPRow();
                int c = temp.getPColn();
                lastMove[0] = r;
                lastMove[1] = c;
                hexCells[r][c] = temp;
                setLastCell(r,c);
                cout << (*this);
                scoreUser1 = 0;
                scoreUser2 = 0;
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
        cout << (*this);;
        round = 0;
    }
    else{
        if(getPlayType() == user){
            cout << "USER2 WINS" << endl;
            cout << (*this);
            round = 0;
        }
        else{
            cout << "COMPUTER WINS" << endl;
            cout << (*this);
            round = 0;
        }
    }
}


ifstream& operator>>(ifstream &is,  Hex& other){
        
        int typePlay ;
        char character ;
        
            is >> other.sizeOfBoard;
            other.setTable();
            is >> other.round;
            is >> typePlay;
            switch(typePlay){
            case 0:
                    other.playType = ifempty;
                    break;
                case 1:
                    other.playType = user;
                    break;
                case 2:
                    other.playType = computer;
                    break;
            }
        
             for(auto i=0 ; i<other.sizeOfBoard ; i++){
                for(auto j=0 ; j<other.sizeOfBoard ; j++){
                    
                    is >> character;
                    switch(character){
                            case 'x':
                                other.hexCells[i][j].setCPosition(user1);
                                break;
                            case 'o':
                                other.hexCells[i][j].setCPosition(user2);
                                break;
                            case '.':
                                other.hexCells[i][j].setCPosition(emptyCell);
                                break;
                            case win1:
                            case win2:
                            break;
                    }
                }
            }
            other.round--;
            return is;
        
}
ofstream& operator<<(ofstream &os, const Hex& other){
    
    int typePlay;
    char character;
    
        os << other.sizeOfBoard << endl;
        os << other.round << endl;
        switch(other.playType){
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
        os << typePlay<< endl;
        
    
        for(auto i=0 ; i<other.sizeOfBoard ; i++){
            
            for(auto j=0 ; j<other.sizeOfBoard ; j++){
                switch(other.hexCells[i][j].getCPosition()){
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
                    os<< character;
            }
            os << endl;
        }
        return os;
}
void Hex::setTable(){
    
    
    hexCells = new Cell*[getSizeOfBoard()]; // allocationg memory in heap
    for(int i=0 ; i < getSizeOfBoard() ; i++){
        hexCells[i] = new Cell[getSizeOfBoard()]; 
    }
    
    for(int i = 0 ; i < getSizeOfBoard() ; i++){
        for(int j=0 ; j < getSizeOfBoard() ; j++){
            hexCells[i][j].setCPosition(emptyCell);
        }
    }
}
void Hex::freeTable(){
    for(int i = 0 ; i < getSizeOfBoard() ; i++){
        delete[] hexCells[i];
    }
    delete[] hexCells;
    hexCells = nullptr;
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
            sizeOfBoard = 0;
            setSizeOfBoard();
        }
        
}
void Hex::displayBoard() {
     
    
    cout << hexCells << endl;
    
}
void Hex::fillLastCellBoard(){
    int all_size = getSizeOfBoard()*getSizeOfBoard();
    
    undoColn = new int[all_size];
    undoRow = new int[all_size];
    for(int i=0 ; i<all_size ; i++){
        undoColn[i]  = -1;
        undoRow[i] = -1;
    }
}
void Hex::deleteLastCell(){
    int all_size = getSizeOfBoard()*getSizeOfBoard();
    for(int i=0 ; i < all_size ; i++){
        if(undoColn[i] == -1 && undoRow[i] == -1){
            undoRow[i-1] = -1;
            undoColn[i-1] = -1;
        }
    }
    
}
int Hex::getLastCellRow(){
    int all_size = getSizeOfBoard()*getSizeOfBoard();
    if(round != 1){
        for(int i=0 ; i < all_size ; i++){
            if(undoRow[i] == -1){
                    return undoRow[i-1];
                    break;
           }
        }
        
    }
    return 0;
}
int Hex::getLastCellColn(){
    int all_size = getSizeOfBoard()*getSizeOfBoard();
    if(round != 1){
        for(int i=0 ; i < all_size ; i++){
            if(undoColn[i] == -1){
                    return undoColn[i-1];
                    break;
           }
        }
        
    }
    return 0;
}
void Hex::setLastCell(const int &move1 = 0, const int &move2 = 0){
    int all_size = getSizeOfBoard()*getSizeOfBoard();
    for(int i=0 ; i < all_size ; i++){
        if(undoColn[i] == -1 && undoRow[i] == -1){
            undoRow[i] = move1;
            undoColn[i] = move2;
            break;
        }
    }
    
}

void Hex::setScoreUser1(const int &score1){
    scoreUser1 = score1;
}
void Hex::setScoreUser2(const int &score2){
    scoreUser2 = score2;
}
