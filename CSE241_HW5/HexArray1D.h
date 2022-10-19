#ifndef HEXARRAY1D_H
#define HEXARRAY1D_H
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "AbstractHex.h"

using namespace std;
class HexArray1D:public AbstractHex{
public:

    HexArray1D()
    {}
    
    HexArray1D(const HexArray1D& rhs);
    
    HexArray1D& operator=(const HexArray1D& rhs);
    
    
    ~HexArray1D(){
        delete[] hexCells;
        hexCells = nullptr;
    }
    
bool right_check(const int &move1,const int &move2);
bool top_check(const int &move1 ,const int &move2);
void setTable();
void playGame();
void setType(against);
    
    
  


bool  operator==(AbstractHex& otherObject)const; // comperation of two Hex games
void print();
void writeToFile(const string&);
void readFromFile(const string&);
void reset();
void setSize(); 
Cell play();
Cell play(int, int);
bool isEnd(int move1,int move2);
int numberOfMoves()const;
Cell operator()(int,int)const;
Cell lastMove()const;



private:
    Cell* hexCells;
    vector<Cell> lastCells;
    

};

#endif // HEXARRAY1D_H

