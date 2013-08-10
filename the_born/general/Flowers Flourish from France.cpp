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

const double EPS = 1e-9;
int cmp(double x, double y = 0, double tol = EPS){
    return( x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

int main(){
  string a, h = "*", s;
  while( getline(cin, s) && s[0] != '*' ){
    a = "";
    bool salir = true;
  	for ( int i = 0; i< s.size() && salir; ++i ) {
  	    if( a == "" && s[i] != ' ' ) a = s[i];
  	    else if( i>0 && s[i-1] == ' ' && s[i] != ' ' && ( s[i] != tolower(a[0]) && s[i] != toupper(a[0]) ) ) salir = false;
  	}
  	if( salir ) cout << "Y" << endl;
  	else cout << "N" << endl;
  }
  return 0;
}
