#ifndef ABSTRACTHEX_H
#define ABSTRACTHEX_H
#include <string>
#include <iostream>
using namespace std;

enum position{ user1, user2, emptyCell, win1, win2}; // it holds user on cell
enum against { ifempty, user, computer}; // which user we would like to play, user or computer



class AbstractHex
{
public:
class Cell{ 
    
    private:
        char pColn = 0;
        char pRow = 0;
        position cPosition = emptyCell;
    public:     
        Cell(char pC, char pR): pColn(pC), pRow(pR)
        {}
        Cell()
        {}
        Cell(position cP): cPosition(cP)
        {}
        Cell(char pC, char pR, position cP): pColn(pC), pRow(pR), cPosition(cP)
        {}
        Cell(const Cell& x){
            pColn = x.pColn;
            pRow = x.pRow;
            cPosition = x.cPosition;
        }
        ~Cell(){}
        
        char get_table_character();

        char getPColn()const{return pColn;}
        char getPRow()const{return pRow;}
        position getCPosition()const{return cPosition;}
        bool operator==(const Cell& other)const;
        void setPColn(const char &c);
        void setPRow(const char &r);
        void setCPosition(const position &cp);
        friend ostream& operator<<(ostream& os, const Cell& rhs){
            os << rhs.pRow << endl;
            os << rhs.pColn << endl;
            os << rhs.cPosition << endl;
        return os;
}
        

        
};

void setPlayType(against type){playType = type;}
void setRound(int rou){round = rou;}
int getSizeOfBoard() const {return sizeOfBoard;}
void setSizeOfBoard(int size){sizeOfBoard = size;}
against getPlayType() const {return playType;}
int getRound()const{return round;}



virtual void print()=0;
virtual void writeToFile(const string&)=0;
virtual void readFromFile(const string&)=0;
virtual void reset() =0;
virtual void setSize() =0;
virtual Cell play() =0;
virtual Cell play(int, int)=0;
virtual bool isEnd(int ,int)=0;
virtual int numberOfMoves()const=0;
virtual Cell operator()(int, int)const=0;
virtual Cell lastMove()const=0;
virtual ~AbstractHex()
{}
size_t round = 0;
virtual bool operator==(AbstractHex&)const =0;

private:
    int sizeOfBoard = 0;
    
    against playType = ifempty;

};


#endif // ABSTRACTHEX_H
