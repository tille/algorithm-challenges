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

using namespace std;

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }
template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }

#define For(i, a, b) for (int i=(a); i<(b); ++i)
#define foreach(x, v) for (typeof (v).begin() x = (v).begin(); x != (v).end(); ++x)
#define D(x) cout << #x " = " << (x) << endl


typedef long long ll;
char result[102][102], minas[102][102];
int r, c;
char a;
int fil[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int col[] = { -1,  0,  1,-1, 1,-1, 0, 1 };

void solve(){
    for ( int i = 0; i< r; ++i ) {
        for ( int j = 0; j < c; ++j ) {
            if( minas[i][j] == '*' ){
                for ( int i2 = 0; i2< 8; ++i2 ) {
                    int n1 = i+fil[i2];
                    int n2 = j+col[i2];
                    if( n1 >= 0 && n1<r && n2 >= 0 && n2 < c ){
                        if( minas[n1][n2] != '*' ){
                            result[n1][n2] = char (int( result[n1][n2] - '0' ) + 1) + '0';
                        }
                    }
                }
                result[i][j] = '*';
            }
        }
    }
}

int main(){
  int cont = 0;
  while( scanf("%d%d",&r,&c) && r+c ){
    for ( int i = 0; i< r; ++i ) {
        for ( int j = 0; j < c; ++j ) {
            cin >> a;
            minas[i][j] = a;
            result[i][j] = '0';
        }
    }
    solve();
    if( cont != 0 ) cout << endl;
    cout << "Field #" << ++cont <<":" << endl;
    for ( int i = 0; i< r; ++i ) {
        for ( int j = 0; j < c; ++j ) {
            cout << result[i][j];
        }
        cout << endl;
    }
  }
  return 0;
}
