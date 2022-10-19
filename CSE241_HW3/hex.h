

#ifndef HEX_H_
#define HEX_H_
#include <iostream>
#include <vector>
#include <string.h>
#include <fstream>

using namespace std;

enum position{ user1, user2, emptyCell, win1, win2};
enum against { ifempty, user, computer};



class Hex
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
        
        void setPColn(char c);
        void setPRow(char r);
        void setCPosition(position cp);
        char get_table_character();
        
        char getPColn(){return pColn;}
        char getPRow(){return pRow;}
        position getCPosition(){return cPosition;}
        
        
        
       
        
    };
    

    
   Hex(){
    
    }
  
    
bool right_check(int move1, int move2);
bool top_check(int move1 , int move2 );
bool final_game(int move1, int move2 );
void play(int move1, int move2);
void play();
void playGame();
void load_game(const string &row);
void save_game(const string &row);
void setTable();
void setType();
void setSizeOfBoard();
void displayBoard();
bool compare_cells(Hex otherObject);


    against getPlayType() const {return playType;}
    int getWidth() const {return sizeOfBoard;}
    int getHeight() const {return sizeOfBoard;}
    int getSizeOfBoard() const {return sizeOfBoard;}


    static int marked_cells(){return count;}
    static int getGames()  {return games;}
    
private:
    vector <vector<Cell> > hexCells;
    int sizeOfBoard = 0;
    against playType = ifempty;
    int lastMove[2];
    static int games ;
    static int round ;
    static int count;

};




#endif // HEX_HPP

