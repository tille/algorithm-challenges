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
#define foreach(x, v) for (typeof (v).begin() x = (v).begin(); \
x != (v).end(); ++x)
#define D(x) cout << #x " = " << (x) << endl

const double EPS = 1e-9;
int cmp(double x, double y = 0, double tol = EPS){
    return( x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

int nums[100];
int visited[100];

int main(){
  int a,b,n,h;
  while( cin >> h >> b && h+b ){

      for( int i = 0; i < b; ++i ){
          cin >> n;
          nums[i] = n;
      }

      memset( visited, 0, sizeof(visited) );
      int cont = 0;

      for ( int i = 0; i < b; ++i ) {
        for ( int a = 0; a < b; ++a ) {

            if( a!=i && visited[abs(nums[i]-nums[a])] != 1 ){
                if( abs(nums[i]-nums[a]) <= h ) cont++;
                visited[abs(nums[i]-nums[a])] = 1;
            }

        }
      }

      if( cont == h ) cout << "Y" << endl;
      else cout << "N" << endl;

  }
  return 0;
}
