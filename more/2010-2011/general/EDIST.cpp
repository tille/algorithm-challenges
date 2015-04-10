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


int array[2100][2100], t;
string c, b;


int main(){
  cin >> t;
  For(h,0,2100) array[h][0] = array[0][h] = h;
  while( t-- ){
    cin >> c >> b;
    for ( int a = 1; a <= c.size() ; ++a ) {
        for ( int i = 1; i<= b.size(); ++i ) {
            int tales = array[a-1][i-1];
            if (c[a-1] != b[i-1]) tales++;
            array[a][i] = min( tales, min(array[a][i-1]+1, array[a-1][i]+1) );
        }
    }
    cout << array[c.size()][b.size()] << endl;
  }
  return 0;
}
