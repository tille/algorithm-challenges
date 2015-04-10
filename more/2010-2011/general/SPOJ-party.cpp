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


template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }
template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }


#define For(i, a, b) for (int i=(a); i<(b); ++i)
#define foreach(x, v) for (typeof (v).begin() x = (v).begin(); x != (v).end(); ++x)
#define D(x) cout << #x " = " << (x) << endl
bool myfunction (int i,int j) return (i>j);


typedef long long ll;


ll acum1, acum2;
int pres, n, costo, funny, t, w, r;
bool salir;
int a[500][500];
int fun[500];
int cost[500];


int main(){
  while( cin >> pres >> n && pres+n ){

    memset(a, 0, sizeof(a));
    memset(fun, 0, sizeof(fun));
    memset(cost, 0, sizeof(cost));

    for( int y = 1; y <= n; ++y ){
        cin >> costo >> funny;
        fun[y] = funny;
        cost[y] = costo;
    }

    for( int i = 1; i <= pres; ++i ){
        for( int j = 1; j <= n; ++j ){
            if( i < cost[j] ) a[i][j] = a[i][j-1];
            else a[i][j] = max( a[i][j-1], a[i-cost[j]][j-1] + fun[j]);
        }
    }

    int idx = 0;
	while( a[idx][n] != a[pres][n]) idx++;

    cout << idx << " " << a[pres][n] << endl;
  }
  return 0;
}
