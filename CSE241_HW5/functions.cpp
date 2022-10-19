#include "functions.h"
#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include "HexVector.h"
#include "HexArray1D.h"
#include "HexAdapter.h"
#include "AbstractHex.h"
#include <queue>
using namespace std;

namespace functions{
    bool func(AbstractHex* arr){
        for(int i=0 ; i<arr[i].getSizeOfBoard() ; i++){
            for(int j=0 ; j<arr[j].getSizeOfBoard() ; j++){
        
                if(!((*arr)(i,j) == user1 ||
                    (*arr)(i,j) == user2 ||
                    (*arr)(i,j) == emptyCell)){
                        return false;
                }
            }
        }
        return true;
    }
    void HexVector1(){
        vector<HexVector> games1;
        
        int choice;
        while(true){
            
            size_t size;
            cout<<  "Menu\n" 
                    << "1-)New Game \n"  
                    << "2-)print\n"
                    << "3-)Write To File\n"
                    << "4-)Read From File\n"
                    << "5-)Reset\n"
                    << "6-)isEnd\n"
                    << "7-)Same Board?\n"
                    << "8-)Last Move\n"
                    << "9-)Number of Moves\n"
                    << "10-)Exit\n" << endl;
            cin >> choice;
            if(choice == 1){ 
                HexVector emptyGame;
                games1.push_back(emptyGame);
                size = games1.size();
                games1[size-1].playGame();
            }
            else if(choice == 2){
                games1.back().print();
                throw;
            }
            else if(choice == 3){
                games1.back().writeToFile("domates.txt");
                throw;
            }
            else if(choice == 4){
                games1.back().readFromFile("domates.txt");
                games1.back().playGame();
                throw;
            }
            else if(choice == 5){
                games1.back().reset();
                games1.back().playGame();
                throw;
            }
            else if(choice == 6){
                cout << games1.back().isEnd(0,0) << endl;
                throw;
            }
            else if(choice == 8){
                cout << games1.back().lastMove() << endl;
                throw;
            }
            else if(choice == 9){
                cout << games1.back().numberOfMoves() << endl;
                throw;
            }
            
            else if(choice == 10){
                break;
            }
           
        }
    }
    void HexArray1D1(){
        vector<HexArray1D> games1;
        
        int choice;
        while(true){
            cout<<  "Menu\n" 
                    << "1-)New Game \n"  
                    << "2-)print\n"
                    << "3-)Write To File\n"
                    << "4-)Read From File\n"
                    << "5-)Reset\n"
                    << "6-)isEnd\n"
                    << "7-)Same Board?\n"
                    << "8-)Last Move\n"
                    << "9-)Number of Moves\n"
                    << "10-)Exit\n" << endl;
            size_t size;
            
            cin >> choice;
            if(choice == 1){ 
                HexArray1D emptyGame;
                games1.push_back(emptyGame);
                size = games1.size();
                games1[size-1].playGame();
            }
            else if(choice == 2){
                games1.back().print();
                throw;
            }
            else if(choice == 3){
                games1.back().writeToFile("domates.txt");
                throw;
            }
            else if(choice == 4){
                games1.back().readFromFile("domates.txt");
                games1.back().playGame();
                throw;
            }
            else if(choice == 5){
                games1.back().reset();
                games1.back().playGame();
                throw;
            }
            else if(choice == 6){
                cout << games1.back().isEnd(0,0) << endl;
                throw;
            }
            else if(choice == 8){
                cout << games1.back().lastMove() << endl;
                throw;
            }
            else if(choice == 9){
                cout << games1.back().numberOfMoves() << endl;
                throw;
            }
            else if(choice == 10){
                break;
            }
           
        }
    }
    void HexAdapter1(){
        vector<HexAdapter<vector>> games1;
             int choice;
        while(true){
            cout<<  "Menu\n" 
                    << "1-)New Game \n"  
                    << "2-)print\n"
                    << "3-)Write To File\n"
                    << "4-)Read From File\n"
                    << "5-)Reset\n"
                    << "6-)isEnd\n"
                    << "7-)Same Board?\n"
                    << "8-)Last Move\n"
                    << "9-)Number of Moves\n"
                    << "10-)Exit\n" << endl;
            size_t size;
            
            cin >> choice;
            if(choice == 1){ 
                HexAdapter<vector> emptyGame;
                games1.push_back(emptyGame);
                size = games1.size();
                games1[size-1].playGame();
            }
            else if(choice == 2){
                games1.back().print();
                throw;
            }
            else if(choice == 3){
                games1.back().writeToFile("domates.txt");
                throw;
            }
            else if(choice == 4){
                games1.back().readFromFile("domates.txt");
                games1.back().playGame();
                throw;
            }
            else if(choice == 5){
                games1.back().reset();
                games1.back().playGame();
                throw;
            }
            else if(choice == 6){
                cout << games1.back().isEnd(0,0) << endl;
                throw;
            }
            else if(choice == 8){
                cout << games1.back().lastMove() << endl;
                throw;
            }
            else if(choice == 9){
                cout << games1.back().numberOfMoves() << endl;
                throw;
            }
            else if(choice == 10){
                break;
            }
           
        }
    }
    
}
