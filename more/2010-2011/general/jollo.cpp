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

#define For(i, a, b) for ( int i=(a); i<(b); ++i )
#define foreach(x, v) for (typeof (v).begin() x = (v).begin(); x != (v).end(); ++x)
#define D(x) cout << #x " = " << (x) << endl

const double EPS = 1e-9;
int cmp(double x, double y = 0, double tol = EPS){
    return( x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

int s[4];
int p[4];

int cmp(){
    int cont = 0, min = 5; // 5 in the minimun it's a value impossible
    for ( int i = 0; i< 3; ++i ) {
      for ( int a = 0; a < 3; ++a ) {
        for ( int b = 0; b < 3; ++b ) {
            if( i != a && a != b && i != b ){
                if( p[i] > s[0] ) cont++;
                if( p[a] > s[1] ) cont++;
                if( p[b] > s[2] ) cont++;
                if( cont < min ) min = cont;
                cont = 0;
            }
        }
      }
    }
    return min;
}

int main(){
  while( scanf("%d %d %d %d %d",&s[0],&s[1],&s[2],&p[0],&p[1]) && (s[0]+s[1]+s[2]+p[0]+p[1]) ){
      int z = -1;
      for ( int i = 1; i < 53; ++i ) {
          p[2] = i;
          if ( cmp() >= 2 && i!=s[0] && i!=s[1] && i!=s[2] && i!=p[0] && i!=p[1]){
            z = i;
            break;
          }
      }
      cout << z << endl;
  }
  return 0;
}
