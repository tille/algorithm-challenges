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
double round(double x){ return floor(x*100)/100; }
double dp[302];

void solve(){
    dp[0] = 0.0;
    for ( int i = 1; i< 301; ++i ) dp[i] = dp[i-1] + 1.0/(i+1) );
}

int main(){
  solve();
  while( cin >> c  && c ){
    int h = 1;
    while( dp[h] < c ) h++;
    cout << h << " " << card(s) << endl;
  }
  return 0;
}
