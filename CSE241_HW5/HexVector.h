#ifndef HEXVECTOR_H
#define HEXVECTOR_H
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "AbstractHex.h"

using namespace std;



class HexVector: public AbstractHex{
public:    

    HexVector()
    {}
    
    
    ~HexVector(){}
    
    
    
    
  
void setTable();
void playGame();
void setType();
bool right_check(const int &move1,const int &move2);
bool top_check(const int &move1 ,const int &move2);

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

virtual bool operator==(AbstractHex&)const;


private:
    vector<Cell> hexCells;
    vector<Cell> lastCells;
    


};
#endif 