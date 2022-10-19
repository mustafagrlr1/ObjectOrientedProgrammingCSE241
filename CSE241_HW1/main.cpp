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
    
    const int sizeOfBoard = categoriesOfTable[sizeOfTable-1];
    
    
    char **game_board = new char*[sizeOfBoard];
    bool **check = new bool*[sizeOfBoard];
    
    for(int i=0 ; i<sizeOfBoard ; i++)
        game_board[i] = new char[sizeOfBoard];
    for(int i=0 ; i<sizeOfBoard ; i++)
        check[i] = new bool[sizeOfBoard];
    
    
    fill_table(game_board, sizeOfBoard);
    play_game(game_board, sizeOfBoard, check);
    

    return 0;
    
}


