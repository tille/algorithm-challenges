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

typedef long long ll;

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }

template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }

#define For(i, a, b) for (int i=(a); i<(b); ++i)
#define D(x) cout << #x " es " << (x) << endl

const double EPS = 1e-9;
int cmp(double x, double y, double tol = EPS)
{ return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1; }

int x[1000];
int y[1000];

int main(){
	int n,k;
	while( cin >> n >> k ){
        if( !n && !k ) break;
        for( int i = 0; i < n; ++i ) cin >> x[i] >> y[i];

        double result = 0;
        for( int i = 0; i < (n-1); ++i ){
            result += sqrt(  (abs(x[i]-x[i+1])*abs(x[i]-x[i+1]))   +    (abs(y[i]-y[i+1])*abs(y[i]-y[i+1]))  );
        }
        printf("%.9lf\n",(result/50)*k);
	}
    return 0;
}
