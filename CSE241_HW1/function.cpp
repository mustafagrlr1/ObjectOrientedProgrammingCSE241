#include <iostream>
#include <string>
#include  "function.h"

using namespace std;

//it holds the data for every round.
int round = 1;


//Shows the winner in Upper Case
char upper_case(char player){
    
    return static_cast<char>(player-32);
}


//fills the table with '.' at the beginning
void fill_table(char **game_board, int sizeOfBoard){
    
    cout << endl;
    
    for(int row=0 ; row<sizeOfBoard ; row++){
        
        for(int coln=0 ; coln<sizeOfBoard ; coln++){
            game_board[row][coln] = '.';
        }
    }
}


//shows board every round
void show_board(char **game_board, int sizeOfBoard){
    
    char a = 97;
    
    
    cout << " ";
    
    for(int i=0 ; i<sizeOfBoard ; i++)
        cout << static_cast<char>(a+i) << " ";
    cout << endl;
    
    for(int i=0 ; i<sizeOfBoard ; i++){
        cout << i+1;
        for(int k=0 ; k<i ; k++){
            cout << " ";
        }
 
        for(int j=0 ; j<sizeOfBoard ; j++){
            
            cout << game_board[i][j] << " ";
            
        }
        
        cout << endl;
        
    }
   
}

//edits board with players move
void edit_board(char **game_board, int sizeOfBoard, int move1, int move2){
  
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
bool check_point(bool **check, int move1, int move2){
    
    if(check[move1][move2] == false)
        return false;
    else
        return true;
    
}


//scans the right to left. begins (move1 0 to sizeOfBoard-1) 
bool right_to_left_check(char **game_board, int sizeOfBoard,bool **check, int move1, int move2){
    
    char  player = 'x';
    check[move1][move2] = true;
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
            if(move1-1 >= 0 && game_board[move1-1][move2] == player && check[move1-1][move2] ==  false)
        
                    if(right_to_left_check(game_board, sizeOfBoard, check, move1-1, move2)){
                        game_board[move1][move2] = upper_case(player);
                        return true;
                        
                    }
        
            if(move1-1 >= 0 && move2+1 < sizeOfBoard && game_board[move1-1][move2+1] == player && check[move1-1][move2+1] == false)
        
                    if(right_to_left_check(game_board, sizeOfBoard, check, move1-1, move2+1)){
                        game_board[move1][move2] = upper_case(player);
                        return true;
                    }
        
            if(move2 >= 0 && game_board[move1][move2-1] == player && check[move1][move2-1] == false)
        
                    if(right_to_left_check(game_board, sizeOfBoard, check, move1, move2-1)){
                        game_board[move1][move2] = upper_case(player);
                        return true;
                    }
        
            if(move2+1 < sizeOfBoard && game_board[move1][move2+1] == player && check[move1][move2+1] == false)
        
                    if(right_to_left_check(game_board, sizeOfBoard, check, move1, move2+1)){
                        game_board[move1][move2] = upper_case(player);
                        return true;
                    }
        
            if(move1+1 < sizeOfBoard && move2-1 >= 0 && game_board[move1+1][move2-1] == player && check[move1+1][move2-1] == false)
        
                    if(right_to_left_check(game_board, sizeOfBoard, check, move1+1, move2-1)){
                        game_board[move1][move2] = upper_case(player);
                        return true;
                    }
        
            if(move1+1 < sizeOfBoard && game_board[move1+1][move2] == player && check[move1+1][move2] == false)
        
                    if(right_to_left_check(game_board, sizeOfBoard, check, move1+1, move2)){
                        game_board[move1][move2] = upper_case(player);
                        return true; 
                    }
        }
        
    }
    
    return false;
    
} 
//scans the top to down. begins (move2 0 to sizeOfBoard-1)
bool top_to_down_check(char **game_board, int sizeOfBoard, bool **check, int move1, int move2){
    check[move1][move2] = true;
    char  player = 'o';
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
            if(move1-1 >= 0 && game_board[move1-1][move2] == player  && check[move1-1][move2] ==  false)
                    if(top_to_down_check(game_board, sizeOfBoard, check, move1-1, move2)){
                        game_board[move1][move2] = upper_case(player);
                        return true;
                    }
            if(move1-1 >= 0 && move2+1 < sizeOfBoard && game_board[move1-1][move2+1] == player && check[move1-1][move2+1] == false)
        
                    if(top_to_down_check(game_board, sizeOfBoard, check, move1-1, move2+1)){
                        game_board[move1][move2] = upper_case(player);
                        return true;
                    }
        
            if(move2 >= 0 && game_board[move1][move2-1] == player && check[move1][move2-1] == false)
        
                    if(top_to_down_check(game_board, sizeOfBoard, check, move1, move2-1)){
                        game_board[move1][move2] = upper_case(player);
                        return true;
                    }
        
            if(move2+1 < sizeOfBoard && game_board[move1][move2+1] == player && check[move1][move2+1] == false)
        
                    if(top_to_down_check(game_board, sizeOfBoard, check, move1, move2+1)){
                        game_board[move1][move2] = upper_case(player);
                        return true;
                    }
        
            if(move1+1 < sizeOfBoard && move2-1 >= 0 && game_board[move1+1][move2-1] == player && check[move1+1][move2-1] == false)
        
                    if(top_to_down_check(game_board, sizeOfBoard, check, move1+1, move2-1)){
                        game_board[move1][move2] = upper_case(player);
                        return true;
                    }
        
            if(move1+1 < sizeOfBoard && game_board[move1+1][move2] == player && check[move1+1][move2] == false)
        
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
bool finish_game(char **game_board, int sizeOfBoard, bool **check, int move1, int move2){
    
    if(round%2 == 0){
        for(int i=0 ; i<sizeOfBoard ; i++){
            if(right_to_left_check(game_board, sizeOfBoard, check, move1, move2)){
                return true;
            }
            move1++;
        }
    }
    else{
        for(int i=0 ; i<sizeOfBoard ; i++){
            if(top_to_down_check(game_board, sizeOfBoard, check, move1, move2)){
                return true;
            }
            move2++;
        }
    }
    return false;
        
}
//computer has a basic operations. Trys to defence against user1.
void computer_move_check(char **game_board, int sizeOfBoard, int move1, int move2){
        
	
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

//Begins game in here
void play_game(char **game_board, int sizeOfBoard, bool **check){
    
    
    char choice;
    cout << "Would you like to play with user or computer?(U/C):";
    cin >> choice;
    
    show_board(game_board, sizeOfBoard);
    
    char row,coln;//takes the input from user
    int move1, move2;//finds the location as a integer datatype
    while(finish_game(game_board,sizeOfBoard, check, 0, 0) != true){
    round++;        
//User1's part        
        if(round%2 == 0){
            cout << "USER1 MOVE:";
            cin >> coln >> row ;
            move1 = static_cast<int>(row-48);
            move2 = static_cast<int>(coln-65);

            edit_board(game_board, sizeOfBoard, move1, move2);
            show_board(game_board, sizeOfBoard);
        }
        else{
//User2's part            
            if(choice == 'U'){
                cout << "USER2 MOVE:";
                cin >> coln >> row;
                int move1 = static_cast<int>(row-48);
                int move2 = static_cast<int>(coln-65);

                edit_board(game_board, sizeOfBoard, move1, move2);
                show_board(game_board, sizeOfBoard);
            }
//Computer's part
            else{
                cout << "COMPUTER MOVE:" << endl;
                computer_move_check(game_board, sizeOfBoard, move1, move2);
                show_board(game_board, sizeOfBoard);
            }
        }
       
//it has to clear inside of the check_board so the program rescans everytime 
        for(int i=0 ; i<sizeOfBoard ; ++i){
            for(int j=0 ; j<sizeOfBoard ; ++j){
                check[i][j] = false;
            }
        }
        
        
    }
    
    show_board(game_board, sizeOfBoard);
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
