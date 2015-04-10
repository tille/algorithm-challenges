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
ll t, a, b, result, sum, n1, n2;

ll reverse_num( ll sourcenum ){
  ll temp = sourcenum;
  ll sum = 0;
  while ( temp ){
    sum *= 10;
    sum += temp%10;
    temp /= 10;
  }
  return sum;
}

int main(){
  cin >> t;
  while( t-- ){
    cin >> a >> b;
    n1 = n2 = sum = result = 0;
    n1 = reverse_num( a );
    n2 = reverse_num( b );
    sum = n1+n2;
    result = reverse_num( sum );
    cout << result << endl;
  }
  return 0;
}
