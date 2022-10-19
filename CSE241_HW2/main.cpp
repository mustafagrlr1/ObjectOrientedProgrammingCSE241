#include <iostream>
#include <string>
#include "function.h"

using namespace std;


int main(){
    
    const int categories = 7; 
    int categoriesOfTable[categories] = {6,7,8,9,10,11,12};
    
    int sizeOfTable;
    cout << "Which size do you want to play?\n"
         << "1-)6x6  \n2-)7x7  \n3-)8x8  \n4-)9x9  \n5-)10x10  \n6-)11x11  \n7-)12x12\n";
            
    cin >> sizeOfTable;
    
    cout << categoriesOfTable[sizeOfTable-1] << endl;
    
    
    
    decltype(categories) sizeOfBoard = categoriesOfTable[sizeOfTable-1];
    
    
    char **game_board = new char*[12];
    
    cells **check = new cells*[12];
    
    for(int i=0 ; i<12 ; i++)
        game_board[i] = new char[12];
        
    for(int i=0 ; i<12 ; i++)
        check[i] = new cells[12];
    
    char choice;
    cout << "Would you like to play with user or computer?(U/C):";
    cin >> choice;
    
    
    fill_table(game_board, sizeOfBoard);
    play_game(game_board, sizeOfBoard, check, choice);
    

    return 0;
    
}
