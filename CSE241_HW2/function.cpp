#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include  "function.h"



using namespace std;

//it holds the data for every round.
int round = 1;


//Shows the winner in Upper Case
char upper_case(const char &player){
    
    return static_cast<char>(player-32);
}


//fills the table with '.' at the beginning
void fill_table(char **game_board,const int &sizeOfBoard){
    
    cout << endl;
    
    for(auto row=0 ; row<sizeOfBoard ; row++){
        
        for(auto coln=0 ; coln<sizeOfBoard ; coln++){
            game_board[row][coln] = '.';
        }
    }
}


//shows board every round
void show_board(char **game_board, const int &sizeOfBoard){
    
    char a = 97;
    
    
    cout << " ";
    
    for(auto i=0 ; i<sizeOfBoard ; i++)
        cout << static_cast<char>(a+i) << " ";
    cout << endl;
    
    for(auto i=0 ; i<sizeOfBoard ; i++){
        cout << i+1;
        for(auto k=0 ; k<i ; k++){
            cout << " ";
        }
 
        for(auto j=0 ; j<sizeOfBoard ; j++){
            
            cout << game_board[i][j] << " ";
            
        }
        
        cout << endl;
        
    }
   
}

//edits board with players move
void edit_board(char **game_board, const int &sizeOfBoard, int move1, int move2){
  
    move1--;
    
    if(game_board[move1][move2] == '.'){
    
        if(round%2 == 0)
            game_board[move1][move2] = 'x';
        else
            game_board[move1][move2] = 'o';
    }
    else{
        cout << "Choose a free '.'  space" << endl;
        round--;
    }
}

//checks the if it is empty, makes the move
bool check_point(cells **check, const int &move1, const int &move2){
    
    if(check[move1][move2] == userOne ){
        cerr << "The cell is occupied by userOne" << endl; 
        return true;
    }
    else if(check[move1][move2] == userTwo ){
        cerr << "The cell is occupied by userOne" << endl; 
        return true;
    
    }
    else{
        cout << "The cell is empty" << endl;
        return false;
    }
}


//scans the right to left. begins (move1 0 to sizeOfBoard-1) 
bool right_to_left_check(char **game_board, const int &sizeOfBoard,cells **check, const int &move1, const int &move2){
    
    cells player = userOne;
    check[move1][move2] = userOne;
    if(game_board[move1][move2] == player){
        //if 'x' wants to win the game left side of the board has to be x and move2 has to reach at the end of the board(sizeOfBoard-1)
	//because scanning all the move2. The purpose is reaching to end of the move2 
        if(game_board[move1][move2] == player && move2 == sizeOfBoard-1){
            game_board[move1][move2] = upper_case(player);
            return true;
        }
	//recursion function
	//scanning around the location and if there is a path, it is keep going otherwise returns false and scans the other locations						
	//if right_to_left_check returns 'true', The path is gonna be uppercase
        else{
            if(move1-1 >= 0 && game_board[move1-1][move2] == player && check_point(check, move1, move2) ==  false)
        
                    if(right_to_left_check(game_board, sizeOfBoard, check, move1-1, move2)){
                        game_board[move1][move2] = upper_case(player);
                        return true;
                        
                    }
        
            if(move1-1 >= 0 && move2+1 < sizeOfBoard && game_board[move1-1][move2+1] == player && check_point(check, move1, move2) == false)
        
                    if(right_to_left_check(game_board, sizeOfBoard, check, move1-1, move2+1)){
                        game_board[move1][move2] = upper_case(player);
                        return true;
                    }
        
            if(move2 >= 0 && game_board[move1][move2-1] == player && check_point(check, move1, move2) == false)
        
                    if(right_to_left_check(game_board, sizeOfBoard, check, move1, move2-1)){
                        game_board[move1][move2] = upper_case(player);
                        return true;
                    }
        
            if(move2+1 < sizeOfBoard && game_board[move1][move2+1] == player && check_point(check, move1, move2) == false)
        
                    if(right_to_left_check(game_board, sizeOfBoard, check, move1, move2+1)){
                        game_board[move1][move2] = upper_case(player);
                        return true;
                    }
        
            if(move1+1 < sizeOfBoard && move2-1 >= 0 && game_board[move1+1][move2-1] == player && check_point(check, move1, move2) == false)
        
                    if(right_to_left_check(game_board, sizeOfBoard, check, move1+1, move2-1)){
                        game_board[move1][move2] = upper_case(player);
                        return true;
                    }
        
            if(move1+1 < sizeOfBoard && game_board[move1+1][move2] == player && check_point(check, move1, move2) == false)
        
                    if(right_to_left_check(game_board, sizeOfBoard, check, move1+1, move2)){
                        game_board[move1][move2] = upper_case(player);
                        return true; 
                    }
        }
        
    }
    
    return false;
    
} 
//scans the top to down. begins (move2 0 to sizeOfBoard-1)
bool top_to_down_check(char **game_board, const int &sizeOfBoard, cells **check, const int &move1, const int &move2){
    check[move1][move2] = userTwo;
    cells  player = userTwo;
    //if 'o' wants to win the game top side of the board has to be 'o' and move1 has to reach at the end of the board(sizeOfBoard-1)
    //because scanning all the move1. The purpose is reaching to end of the move1 
    if(game_board[move1][move2] == player){
        
        if(game_board[move1][move2] == player && move1 == sizeOfBoard-1){
            game_board[move1][move2] = upper_case(player);
            return true;
        }
	//recursion function
	//scanning around the location and if there is a path, it is keep going otherwise returns false and scans the other locations
	//if top_to_down_check returns 'true', The path is gonna be uppercase
        else{
            if(move1-1 >= 0 && game_board[move1-1][move2] == player  && check_point(check, move1, move2) ==  false)
                    if(top_to_down_check(game_board, sizeOfBoard, check, move1-1, move2)){
                        game_board[move1][move2] = upper_case(player);
                        return true;
                    }
            if(move1-1 >= 0 && move2+1 < sizeOfBoard && game_board[move1-1][move2+1] == player && check_point(check, move1, move2) == false)
        
                    if(top_to_down_check(game_board, sizeOfBoard, check, move1-1, move2+1)){
                        game_board[move1][move2] = upper_case(player);
                        return true;
                    }
        
            if(move2 >= 0 && game_board[move1][move2-1] == player && check_point(check, move1, move2) == false)
        
                    if(top_to_down_check(game_board, sizeOfBoard, check, move1, move2-1)){
                        game_board[move1][move2] = upper_case(player);
                        return true;
                    }
        
            if(move2+1 < sizeOfBoard && game_board[move1][move2+1] == player && check_point(check, move1, move2) == false)
        
                    if(top_to_down_check(game_board, sizeOfBoard, check, move1, move2+1)){
                        game_board[move1][move2] = upper_case(player);
                        return true;
                    }
        
            if(move1+1 < sizeOfBoard && move2-1 >= 0 && game_board[move1+1][move2-1] == player && check_point(check, move1, move2) == false)
        
                    if(top_to_down_check(game_board, sizeOfBoard, check, move1+1, move2-1)){
                        game_board[move1][move2] = upper_case(player);
                        return true;
                    }
        
            if(move1+1 < sizeOfBoard && game_board[move1+1][move2] == player && check_point(check, move1, move2) == false)
        
                    if(top_to_down_check(game_board, sizeOfBoard, check, move1+1, move2)){
                        game_board[move1][move2] = upper_case(player);
                        return true; 
                    }
        }
        
    }
    
    return false;
    
}
//enters all the time before while statement began at play_game function, controls the game if one of the user reachs the end
//moves has to be incremented in the loop because move1 right to left and has to control every part of the program upsidedown.Same thing is valid for move2 
bool finish_game(char **game_board, const int &sizeOfBoard, cells **check,int move1,int move2){
    
    if(round%2 == 0){
        for(auto i=0 ; i<sizeOfBoard ; i++){
            if(right_to_left_check(game_board, sizeOfBoard, check, move1, move2)){
                return true;
            }
            move1++;
        }
    }
    else{
        for(auto i=0 ; i<sizeOfBoard ; i++){
            if(top_to_down_check(game_board, sizeOfBoard, check, move1, move2)){
                return true;
            }
            move2++;
        }
    }
    return false;
        
}
//computer has a basic operations. Trys to defence against user1.
void computer_move_check(char **game_board, const int &sizeOfBoard, int move1, int move2){
        
	
        move1--;//indexes has to be decrement because user types 1-sizeOfBoard
    
        if(move2+1 < sizeOfBoard && game_board[move1][move2+1] == '.'){
            move1++;
            
            edit_board(game_board, sizeOfBoard, move1, move2+1);
        } 
        else if(move1-1 >= 0 && move2+1 < sizeOfBoard && game_board[move1-1][move2+1] == '.'){
            move1++;
            
            edit_board(game_board, sizeOfBoard, move1-1, move2+1);
        }
        else if(move1+1 < sizeOfBoard && game_board[move1+1][move2] == '.'){
            move1++;
            edit_board(game_board, sizeOfBoard, move1+1, move2);
        }
        else if(move1+1 < sizeOfBoard && move2-1 >= 0 && game_board[move1+1][move2-1] == '.'){
            move1++;
            edit_board(game_board, sizeOfBoard, move1+1, move2-1);
        }
        else if(move1-1 >= 0 && game_board[move1-1][move2] == '.'){
            move1++;
            edit_board(game_board, sizeOfBoard, move1-1, move2);
        }
        else if(move2-1 >= 0 && game_board[move1][move2-1] == '.'){
            move1++;
            edit_board(game_board, sizeOfBoard, move1, move2-1);
        }
    
}

//game_board has been filled by the last saved text file also it takes size of board , round number, and
//the chocice that user choose which player or computer it wants to play.
void load_game(char **game_board, int &sizeOfBoard, string row, char &choice){
        
        ifstream file;
    
        file.open(row);
        
        if(file.is_open()){
            file >> sizeOfBoard;
            file >> round;
            file >> choice;
            
             for(auto i=0 ; i<sizeOfBoard ; i++){
                for(auto j=0 ; j<sizeOfBoard ; j++){
                    
                    file >> game_board[i][j];
                 
                }
            }
              
                file.close();
            
        }   
        else cerr << "Unable to open file" ;
        
        
    
    
}

//computer saves the current game in a text file with size of board ,row and choice
void save_game(char **game_board, int &sizeOfBoard, string row,char choice){
    ofstream myfile (row);
    
    if(myfile.is_open()){
        myfile << sizeOfBoard << endl;
        myfile << round << endl;
        myfile << choice << endl;
        for(auto i=0 ; i<sizeOfBoard ; i++){
            
            for(auto j=0 ; j<sizeOfBoard ; j++){
                myfile << game_board[i][j];
            }
            myfile << endl;
        }
        
        myfile.close();
    }
    else{
        cerr << "unable to open file" << endl;
    }
    
    exit(0);
        
}



//Begins game in here
void play_game(char **game_board, int sizeOfBoard, cells **check, char choice){
    
    
    cin.ignore();
    string row,coln;//takes the input from user
    
    int move1, move2;//finds the location as a integer datatype
    while(finish_game(game_board,sizeOfBoard, check, 0, 0) != true){
    round++;        
//User1's part        
        if(round%2 == 0){
            cout << "USER1 MOVE:";
        
            getline(cin,coln,' ');
            getline(cin,row);
             
            if(coln == "LOAD"){// Load's part for user1 
                load_game(game_board, sizeOfBoard, row, choice);
                show_board(game_board, sizeOfBoard);
                continue;
            }
            else if(coln == "SAVE"){//Save's part for user1
                save_game(game_board, sizeOfBoard, row, choice);
                
            }
            
        
            char charColn = coln[0];
            
         
            move1 = stoi(row);
            move2 = static_cast<int>(charColn-65);

            edit_board(game_board, sizeOfBoard, move1, move2);
            show_board(game_board, sizeOfBoard);
        }
        else{
//User2's part            
            if(choice == 'U'){
                cout << "USER2 MOVE:";
                getline(cin,coln,' ');
               
            
                //cin.ignore();
                getline(cin,row);       
                if(coln == "LOAD"){// Load's part for user1 
                    load_game(game_board, sizeOfBoard, row, choice);
                    continue;
                }
                else if(coln == "SAVE"){// Save's part for user1 
                    save_game(game_board, sizeOfBoard, row, choice);
                    
                }
                 

            
         
                char charColn = coln[0];
                int move1 = stoi(row);
                int move2 = static_cast<int>(charColn-65);
                
                edit_board(game_board, sizeOfBoard, move1, move2);
                show_board(game_board, sizeOfBoard);
            }
//Computer's part
            else if(choice == 'U'){
                cout << "COMPUTER MOVE:" << endl;
                computer_move_check(game_board, sizeOfBoard, move1, move2);
                show_board(game_board, sizeOfBoard);
            }
            else{
                cerr << "Wrong comment for choice" << endl;
                exit(0);
            }
        }
       
//it has to clear inside of the check_board so the program rescans everytime 
        for(auto i=0 ; i<sizeOfBoard ; ++i){
            for(auto j=0 ; j<sizeOfBoard ; ++j){
                check[i][j] = emptyCell;
            }
        }
        
        
    }

    if(round%2 == 0){
        cout << "USER1 WINS" << endl;
    }
    else{
        if(choice == 'U'){
            cout << "USER2 WINS" << endl;
        }
        else{
            cout << "COMPUTER WINS" << endl;
        }
    }
    
}
