#include <iostream>
#include <vector>
#include <cstdlib>

#include "functions.h"

using namespace std;
using namespace functions;


int main(){
    
    int choice;
    try{
        while(true){
            cout <<"Which type do you want to play?\n" 
                <<"1-)HexVector\n"
                <<"2-)HexArray1D\n"
                <<"3-)HexAdapter\n"
                <<"4-)Exit\n"
                <<"Your choice:";
            cin >> choice;

            if(choice == 1){
                HexVector1();
            }
            else if(choice == 2){
                HexArray1D1();
            }
            else if(choice == 3){
                HexAdapter1();
            }
            else if(choice == 4){
                exit(1);
            }
            else{
                cout << "wrong choice!!!! try again\n " << endl;
            }
            
        }
    }
    catch(...){
        cerr << "Error!" << endl;
        exit(1);
    }
        
}

