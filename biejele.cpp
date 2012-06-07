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

//cuando se va a trabajar con enteros
//la suma es con 5 y no con 0.5
double round(double x){ return floor(x*100+0.5)/100; }

bool myfunction (int i,int j) { return (i>j); }

long long reverse_num( ll sourcenum ){
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
    int n[6];
    int result[6] = {1,1,2,2,2,8};
    while( cin >> n[0] >> n[1] >> n[2] >> n[3] >> n[4] >> n[5] ){
        for( int i = 0; i < 6; ++i ){
            cout << result[i]-n[i];
            if( i != 5 ) cout << " ";
        }
        cout << endl;
    }
    return 0;
}
