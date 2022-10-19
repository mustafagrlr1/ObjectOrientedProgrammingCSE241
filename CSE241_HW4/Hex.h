
#ifndef HEX_H_
#define HEX_H_
#include <iostream>
#include <vector>
#include <string.h>
#include <fstream>
#include <cstdlib>
#include <time.h>

using namespace std;

enum position{ user1, user2, emptyCell, win1, win2}; // it holds user on cell
enum against { ifempty, user, computer}; // which user we would like to play, user or computer

class Cell{ 
    
    private:
        char pColn = 0;
        char pRow = 0;
        position cPosition = emptyCell;
   public:     
        explicit Cell(char pC, char pR): pColn(pC), pRow(pR)
        {}
        explicit Cell()
        {}
        explicit Cell(position cP): cPosition(cP)
        {}
        explicit Cell(char pC, char pR, position cP): pColn(pC), pRow(pR), cPosition(cP)
        {}
        
        void setPColn(const char &c);
        void setPRow(const char &r);
        void setCPosition(const position &cp);
        char get_table_character();
        
        char getPColn(){return pColn;}
        char getPRow(){return pRow;}
        position getCPosition(){return cPosition;}

        
    };

class Hex
{
public:
    
   explicit Hex()
   {}
   explicit Hex(int score1, int score2): scoreUser1(score1), scoreUser2(score2)
   {}
   explicit Hex(int size): sizeOfBoard(size)
   {}
   explicit Hex(against type): playType(type)
   {}

friend ifstream& operator>>(ifstream &is,Hex& other);   

friend ofstream& operator<<(ofstream &os, const Hex& other);
friend ostream& operator<<(ostream &os, const Hex& other);

bool right_check(const int &move1,const int &move2); // It scans the board for situation of 'X' player winning (right to left)
bool top_check(const int &move1 ,const int &move2 );// It scans the board for situation of 'O' player winning (top to down)
bool final_game(int move1, int move2 ); // sends the data to checking board depends on round
Cell play(int, int);
Cell play();
void playGame(); // Program is running in here
void load_game(const string &row);
void save_game(const string &row);
void freeTable(); // deletes all the data inside of board
void setTable(); // creates a new board
void setType(); 
void setSizeOfBoard();
void setScoreUser1(const int &score1);
void setScoreUser2(const int &score2);
void displayBoard();

int getScore();


void operator--(int); // postfix -- operator deletes the last element
void operator--(); // prefix -- operator deletes the last element // same as postfix operator
bool   operator==(const Hex &otherObject)const ; // comperation of two Hex games

void fillLastCellBoard();
void deleteLastCell(); // deletes only the last move 
int getLastCellRow();
int getLastCellColn();
void setLastCell(const int &move1, const int &move2);

    against getPlayType() const {return playType;}
    int getWidth() const {return sizeOfBoard;}
    int getHeight() const {return sizeOfBoard;}
    int getSizeOfBoard() const {return sizeOfBoard;}
    
    int getScoreUser1()const{return scoreUser1;}
    int getScoreUser2()const{return scoreUser2;}

    static int marked_cells(){return count;}
    static int getGames(){return games;}
    
private:
    Cell** hexCells;
    int* undoRow;
    int* undoColn; 
    int sizeOfBoard = 0;
    against playType = ifempty;
    string text;
    int lastMove[2];
    static int games ;
    int round = 0 ;
    static int count;
    int scoreUser1 = 0;
    int scoreUser2 = 0;

};




#endif // HEX_HPP