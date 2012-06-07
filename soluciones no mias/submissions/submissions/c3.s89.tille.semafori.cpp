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

int main(){
    int n,l,d,r,g,p = 0, result = 0;
    cin >> n >> l;
    for( int i = 0; i < n; ++i ){
        cin >> d >> r >> g;
        int dist = result+(d-p);
        if( dist%(r+g) < r ) result = dist+(r-(dist%(r+g)));
        else result += (d-p);
        p = d;
    }
    result += (l-p);
    cout << result << endl;
    return 0;
}
