using namespace std;
#include <algorithm>
#include <iostream>
#include <iterator>
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

typedef long long ll;

int rows[9+2][9+2];
int cols[9+2][9+2];
int squares[3][3][9+2];
char sudoku[9+2][9+2];
int negattive = 0, maybe = 0, temp1, temp2, tales = 0, salir;

void solve(int i, int j, int k){
    if( sudoku[i][j] != '.' && sudoku[i][j] == char(k+'0') ) tales = 1;
    else if( sudoku[i][j] != '.' && sudoku[i][j] != char(k+'0') ) negattive++;
    else if( sudoku[i][j] == '.' && (cols[j][k] || rows[i][k] || squares[i/3][j/3][k]) ) negattive++;
    else if( sudoku[i][j] == '.' && !cols[j][k] && !rows[i][k] && !squares[i/3][j/3][k] ){
        maybe++;
        temp1 = i; temp2 = j;
    }
}

void comprobar(){
    for( int i = 0; i < 9; i=i+3 ){
        for( int j = 0; j < 9; j=j+3 ){
            for( int k = 1; k <= 9; ++k ){
                maybe = negattive = temp1 = temp2 = tales = 0;
                solve(i,j,k); solve(i,j+1,k); solve(i,j+2,k);
                solve(i+1,j,k); solve(i+1,j+1,k); solve(i+1,j+2,k);
                solve(i+2,j,k); solve(i+2,j+1,k); solve(i+2,j+2,k);
                if( tales == 1 ) continue;
                else if( negattive == 9 ){ salir = i = k = j = 10;
                }else if( maybe == 1 ){
                    sudoku[temp1][temp2] = char(k+'0');
                    cols[temp2][k] = 1;
                    rows[temp1][k] = 1;
                    squares[temp1/3][temp2/3][k] = 1;
                }
            }
        }
    }
}

int main(){
    string s;
    char c;
    salir = 0;
    for( int i = 0; i< 9; ++i ){
        for( int j = 0; j < 9 ; ++j ){
            cin >> c;
            sudoku[i][j] = c;
            if( c != '.' ){
                if( squares[i/3][j/3][c-'0'] || cols[j][c-'0'] || rows[i][c-'0'] ){
                    salir = 10;
                }else{
                    squares[i/3][j/3][c-'0'] = 1;
                    cols[j][c-'0'] = 1;
                    rows[i][c-'0'] = 1;
                }
            }
        }
    }

    for( int i = 0; i < 9 && !salir; ++i ) comprobar();
    //cout << endl;
    for( int i = 0; i < 9 && !salir; ++i ){
        for( int j = 0; j < 9; ++j ){
            cout << sudoku[i][j];
        }
        cout << endl;
    }
    if( salir ) cout << "ERROR" << endl;
    return 0;
}
