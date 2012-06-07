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

int p[100005], ip[100005], n;

int main(){
    while( cin >> n && n ){
        bool salir = true;
        for( int i = 1; i <= n; ++i ){
            cin >> p[i];
            ip[p[i]] = i;
        }
        for( int i = 1; i<=n && salir ; ++i ) if( p[i] != ip[i] ) salir = false;
        if( !salir ) cout << "not ambiguous" << endl;
        else cout << "ambiguous" << endl;
    }
    return 0;
}
