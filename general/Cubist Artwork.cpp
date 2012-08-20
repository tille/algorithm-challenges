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

int a[30], b[30], n,t,temp,acum;

int main(){
    while( cin >> n >> t && (n+t) ){
        temp = acum = 0;
        memset( a, 0, sizeof a);
        memset( b, 0, sizeof b);
        for( int i = 0; i<n; ++i){
            cin >> temp;
            a[temp] += 1;
            acum+=temp;
        }
        for( int i = 0; i<t; ++i){
            cin >> temp;
            b[temp] += 1;
        }
        for( int i = 0; i < 25; ++i){
            if(  b[i] > 0 && b[i] > a[i]) acum += (b[i]-a[i])*i;
        }

        cout << acum << endl;
    }
    return 0;
}
