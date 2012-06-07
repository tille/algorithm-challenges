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

int array[210][210];
int k[210];
ll n, m, cont;
int salir;
string s;


void solved(){
    for ( int i = 0; i< n; ++i ) {
        cont = salir = 0;
        for ( int a = 0; a < m; ++a ) {
            if( array[a][i] != 1 && !salir ) salir = 1;
            if( salir && array[a][i] == 1 && array[a-1][i] == 0 ){
                k[cont]++;
                salir = cont = 0;
            }else if( a == m-1 && array[a][i] == 0 ) k[cont+1]++;
            if( salir ) cont++;
        }
    }
    For( j, 1, m+1 ) if( k[j] ) cout << j << " " << k[j] << endl;
}

int main(){
  while( cin >> m >> n && n+m ){

    memset(array,0,sizeof(array));
    memset(k,0,sizeof(k));

    for ( int i = 0; i< m; ++i ) {
        cin >> s;
        for ( int a = 0; a < n; ++a ) array[i][a] = s[a]-'0';
    }

    solved();
  }
  return 0;
}
