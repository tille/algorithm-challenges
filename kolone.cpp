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
    int n,m,t;
    string row1, row2;
    while( cin >> n >> m ){

        cin >> row1 >> row2;
        cin >> t;
        string result = "";

        for( int i = n-1; i > -1; --i ) result = result + row1[i];
        for( int i = 0; i < n; ++i ) row2 = " " + row2;

        row1 = result;
        for( int i = 0; i < t; ++i ) row1 = " " + row1;

        for( int i = 0; i < max(row1.size(),row2.size()); ++i ){
            if( i < row2.size() && int(row2[i]) != 32 ) cout << row2[i];
            if( i < row1.size() && int(row1[i]) != 32 ) cout << row1[i];
        }
        cout << endl;
    }
    return 0;
}
