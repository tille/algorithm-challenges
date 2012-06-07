// Andrés Mejía y Ana Echavarría
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
int r, c;
char board [105][105];

void topLeft (){
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            board[i][c + j] = board[i][c - 1 - j]; 
        }
    }
}

void bottom (){
    for (int i = r - 1; i >=0; i--){
        for (int j = 0; j < 2 * c; j++){
            board[2 * r - 1 - i][j] = board[i][j]; 
        }
    }
}


int main(){
    cin >> r >> c;
    for (int i = 0; i < r; i++){
        string line;
        cin >> line;
        for (int j = 0; j < c; j++){
            board[i][j] = line[j];
        }
    }
    
    topLeft();
    bottom();
    
    int i, j;
    cin >> i >> j;
    i--; j--;
    if (board[i][j] == '.'){
        board[i][j] = '#';
    }else{
        board[i][j] = '.';
    }
    
    for (int i = 0; i < 2 * r; i++){
        for (int j = 0; j < 2 * c; j++){
            cout << board[i][j];
        }
        cout << endl;
    }
    return 0;
}