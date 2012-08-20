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

int main(){
    int n; string s;
    cin >> n;
    map<string,int> kids;
    int cont = 0, tot = 0;

    for( int i = 0; i < n; ++i ){
        cin >> s;
        kids[s]++; tot++;
        int temp = tot-kids[s];
        if( (kids[s]-1) > temp ) cont++;
    }
    cout << cont << endl;
    return 0;
}
