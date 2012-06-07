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
int n;
double num, acum, result, prom, result2;
double nums[10004];

double round(double x){ return floor(x*100+0.5)/100; }

int main(){
  while( cin >> n && n ){
    acum = 0;
    for ( int i = 0; i< n ; ++i ) {
        cin >> num;
        acum += num;
        nums[i] = num;
    }

    result = prom = result2 = 0;
    //acum = round(acum);
    prom = acum / n;
    prom = round(prom);

    for ( int j = 0; j < n; ++j ){
        if( nums[j] > prom ) result += nums[j]-prom;
        else result2 += prom-nums[j];
    }
    printf("$%.2f\n",(result < result2)?result:result2);

  }
  return 0;
}
