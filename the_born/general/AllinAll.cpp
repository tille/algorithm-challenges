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
string s, t;

int main(){
  bool salir = true;
  while( cin >> s >> t  ){
    int temp = 0,cont = 0;
    for ( int i = 0; i< s.size(); ++i ) {
      for ( int j = temp; j< t.size(); ++j ) {
        if( s[i] == t[j] ){
          temp = j+1;
          cont++;
          break;
        }
      }
    }
    if (cont == s.size() ) cout << "Yes" << endl;
    else cout << "No" << endl;
  }
  return 0;
}
