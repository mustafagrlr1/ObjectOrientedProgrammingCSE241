#include <string>
#include <iostream>
#include "AbstractHex.h"
using namespace std;

char AbstractHex::Cell::get_table_character(){
        if(getCPosition() == win1){return 'X';}
            else if(getCPosition() == win2){return 'O';}
            else if(getCPosition() == user1){return 'x';}
            else if(getCPosition() == user2){return 'o';}
            else{ return '.';}
                
        }
bool AbstractHex::Cell::operator==(const Cell& other)const{
        return (this->cPosition == other.cPosition && 
                this->pColn== other.pColn &&
                this->pRow == other.pRow);
        }
void AbstractHex::Cell::setPColn(const char &c){
        pRow = c;
        }
void AbstractHex::Cell::setPRow(const char &r){
        pColn = r;
        }
void AbstractHex::Cell::setCPosition(const position &cp){
        cPosition = cp;
        }
