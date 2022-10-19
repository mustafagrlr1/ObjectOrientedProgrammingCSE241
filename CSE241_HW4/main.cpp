#include <iostream>
#include <vector>
#include "Hex.h"
#include <fstream>
#include <cstdlib>

using namespace std;

int Hex::games = 0;  // counts the games until 5
int Hex::count = 0; // counts the marked cells

int main(){
    
    vector<Hex> games;
    
    while(true){
        cout << "Menu\n" 
                << "1-)New Game \n"      
                << "2-)Load Game\n"
                << "3-)Print Total Marked Cells\n"
                << "4-)Compare Games\n" 
                << "5-)Exit "<< endl;
        size_t size , game;
        int choice;
        cin >> choice;
        if(choice == 1){ 
            
                Hex emptyGame;
                games.push_back(emptyGame);
                size = games.size();
                games[size-1].playGame();
        }
        else if(choice == 2){
            for(size_t i=0 ; i < games.size() ; i++){
                cout << i+1 << ".game" << endl;
            }
            cout << "Select the game:" ;
            cin >> game;
            if(game-1 < games.size()){
                    games[game-1].playGame();
            }
            else{
                    cerr << "Total game is : " << games.size() << endl;
            }
        }
        else if(choice == 3){
            for(size_t i=0 ; i < games.size() ; i++){
                cout << i+1 << ".game" << endl;
            }
            
            cout << "Total marked Cells are : " << Hex::marked_cells() << endl;
        }
        else if(choice == 4){
            size_t first , second;
            for(size_t i=0 ; i < games.size() ; i++){
                cout << i+1 << ".game" << endl;
            }
            cout << "Select first game:" ;
            cin >> first;
            cout << "Select second game:";
            cin >> second;
        if(first -1 < games.size() && second-1 < games.size()){
            if(games[first-1] == (games[second-1])){ // Operator== is here 
                cout << first << ". game has more marked cells" <<endl;
            }
            else{
                cout << second << ". game has mor marked cells" << endl;
            }
        }
        else{
                cerr << "Invalid game number" << endl;
        }
        }
    else if(choice == 5){
        return 0;
    }
        else{
                cerr << "Invalid choice" << endl;
            
            }
    }
    return 0;
}