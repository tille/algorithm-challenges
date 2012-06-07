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

int times[100+5];

int main(){
    int a,b,c;
    cin >> a >> b >> c;
    for( int i = 0; i < 3; ++i ){
        int n1, n2;
        cin >> n1 >> n2;
        for( int i = n1; i < n2; ++i ){
            times[i]++;
        }
    }
    int acum = 0;
    for( int i = 0; i < 101; ++i ){
        if( times[i] == 1 ) acum += times[i]*a;
        else if( times[i] == 2 ) acum += times[i]*b;
        else if( times[i] == 3 ) acum += times[i]*c;
    }
    cout << acum << endl;
    return 0;
}
