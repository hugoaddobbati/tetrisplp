#include <bits/stdc++.h>
#include <unistd.h>
#include <stdio.h>
#include <ctime>
#include <linux/input.h>
#include <stdio.h>
#include "keyboard.h"
using namespace std;


void drawGrid(vector<vector<string>> grid){
    for(int l = 0; l < 52; l++){
        cout << "#";
    }
    cout << endl;
    for(int l = 0; l < 40; l++){
        cout << "#";
        for(int j = 0; j < 50; j++){
            cout << grid[l][j];
        }      
        cout << "#" <<  endl;
    }
    for(int l = 0; l < 52; l++){
        cout << "#";
    }
    cout << endl;
}


int main(){
    cKeyboard kb;

    system("clear");
    char key = getch();
    sleep(1);
    vector<vector<string>> marray;
    for(int i = 0; i < 40; i++){
        vector<string> tmp = {};
        for(int k = 0; k < 50; k++){
            tmp.push_back(" ");
        }
        marray.push_back(tmp);
    }
    srand(time(NULL));
    int middle = 24;
    while(true){
        marray[0][middle] = "0";
        int m = 0;
        drawGrid(marray);
        while(true){
            usleep(500000);
            system("clear");
            if(m < 39 && marray[m+1][middle] == " "){
                string tmp = marray[m][middle];
                marray[m][middle] = marray[m+1][middle];
                marray[m+1][middle] = tmp;
                m++;
            }
            else{
                break;
            }
            drawGrid(marray);
            
        }    
    }

    return 0;
    
}

