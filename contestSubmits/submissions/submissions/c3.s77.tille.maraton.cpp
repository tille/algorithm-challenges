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

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }

template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }

string tricky[30+5];

int main(){
    int n;
    cin >> n;
    for( int i = 0; i < n; ++i ) cin >> tricky[i];
        int m = n;
        int salir = 1;
        for( int i = 0; i < n && salir; ++i ){
            for( int j = 0; j < n && salir; ++j ){
                if(  (i+1) < n && (j+1) < m && (i+2) < n && (j+2) < m && tricky[i][j] == tricky[i+1][j+1] && tricky[i][j]==tricky[i+2][j+2] && tricky[i][j] != '.'){
                    cout << tricky[i][j] << endl;
                    salir = 0;
                }else if( i < n && (i+1)<n && (i+2)<n && j < m && tricky[i][j] == tricky[i+1][j] && tricky[i][j]==tricky[i+2][j] && tricky[i][j] != '.' ){
                    cout << tricky[i][j] << endl;
                    salir = 0;
                }else if( i < n && (j+1)<m && (j+2)<m && j < m && tricky[i][j] == tricky[i][j+1] && tricky[i][j]==tricky[i][j+2] && tricky[i][j] != '.'){
                    cout << tricky[i][j] << endl;
                    salir = 0;
                }
            }
        }
        if( salir ) cout << "ongoing" << endl;
    return 0;
}
