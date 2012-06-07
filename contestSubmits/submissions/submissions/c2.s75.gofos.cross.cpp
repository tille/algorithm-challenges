// Andrés Mejía
using namespace std;
#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <sstream>
#include <fstream>
#include <cassert>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <map>
#include <set>

////////////// Prewritten code follows. Look down for solution. ////////////////
#define foreach(x, v) for (typeof (v).begin() x=(v).begin(); x !=(v).end(); ++x)
#define For(i, a, b) for (int i=(a); i<(b); ++i)
#define D(x) cout << #x " is " << (x) << endl

const double EPS = 1e-9;
int cmp(double x, double y = 0, double tol = EPS) {
    return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}
////////////////////////// Solution starts below. //////////////////////////////
int board [9][9];

pair<bool, bool> cross(char a){
    bool could = false;
    
    bool burnCol [] = {0,0,0,0,0,0,0,0,0};
    bool burnRow [] = {0,0,0,0,0,0,0,0,0};
    for (int i = 0; i < 9; i++){
        for (int j = 0; j < 9; j++){
            if (board[i][j] == a){
                burnRow[i] = true;
                burnCol[j] = true;
            }
        }
    }
    
    //Check boxes
    int di [] = {0,0,0,1,1,1,2,2,2};
    int dj [] = {0,1,2,0,1,2,0,1,2};
    for (int i = 0; i < 9; i += 3){
        for (int j = 0; j < 9; j += 3){
            int ci = i; int cj = j;
            bool inBox = false;
            for (int k = 0; k < 9; k++){
                if (board[ci + di[k]][cj + dj[k]] == a) inBox = true;
            }
            int placeCount = 0;
            int placei = 0;
            int placej = 0;
            if (!inBox){
                //Check whether there is exactly one spot where to place it
                for (int k = 0; k < 9; k++){
                    int posi = ci + di[k];
                    int posj = cj + dj[k];
                    if (burnRow[posi] or burnCol[posj]) continue;
                    if (board[posi][posj] == '.'){
                        placeCount++;
                        placei = posi;
                        placej = posj;
                    }
                }
                if (placeCount == 0) return make_pair(false, true);
                if (placeCount == 1){
                    //printf("Placed char %c in pos %d, %d\n", a, placei, placej);
                    board[placei][placej] = a;
                    could = true;
                }
            }
                
        }
    }
    return make_pair(could, false);
}

bool isValid(){
    //Check rows
    for (int i = 0; i < 9; i++){
        int count [] = {0,0,0,0,0,0,0,0,0};
        for (int j = 0; j < 9; j++){
            if (board[i][j] != '.'){
                int pos = board[i][j] - '1';
                count[pos]++;
                if (count[pos]++ >= 2) return false;
            }
        }
    }
    //Check columns
    for (int j = 0; j < 9; j++){
        int count [] = {0,0,0,0,0,0,0,0,0};
        for (int i = 0; i < 9; i++){
            if (board[i][j] != '.'){
                int pos = board[i][j] - '1';
                count[pos]++;
                if (count[pos]++ >= 2) return false;
            }
        }
    }
    
    //Check boxes
    int di [] = {0,0,0,1,1,1,2,2,2};
    int dj [] = {0,1,2,0,1,2,0,1,2};
    for (int i = 0; i < 9; i += 3){
        for (int j = 0; j < 9; j += 3){
            int count [] = {0,0,0,0,0,0,0,0,0};
            int ci = i; int cj = j;
            for (int k = 0; k < 9; k++){
                if (board[ci + di[k]][cj + dj[k]] != '.'){
                    int pos = board[ci + di[k]][cj + dj[k]] - '1';
                    count[pos]++;
                    if (count[pos]++ >= 2) return false;
                }
            
            }
                
        }
    }
    
    return true;
}


void print(){
    for (int i = 0; i < 9; i++){
        for (int j = 0; j < 9; j++){
            cout << (char)board[i][j];
        }
        cout << endl;
    }
}

int main(){
    string line;
    for (int i = 0; i < 9; i++){
        cin >> line;
        for (int j = 0; j < 9; j++){
            board[i][j] = line[j];
        }
    }
    
    if (isValid()){
      bool repeat = true;
      bool error = false;
      while (repeat and !error){
          repeat = false;        
          for (char i = '1'; i <= '9' and !error; i++){
              if(cross(i).first) repeat = true;
              if(cross(i).second) error = true;
          }
      }
      if (error){
          cout << "ERROR" << endl;
      }else{
          print();
      }
        
    }else{
        cout << "ERROR" << endl;
    }
    
    
    
    return 0;
}