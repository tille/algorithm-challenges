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

string cards[100+5];

int main(){
    int n, m, a, b;
    while( cin >> n >> m ) {
        for( int i = 0; i < n; ++i ){
            cin >> cards[i];
            for( int j = cards[i].size()-1; j > -1; --j ) cards[i] = cards[i] + cards[i][j];
            cards[((n*2)-i)-1] = cards[i];
        }

        cin >> a >> b;
        cards[a-1][b-1] = (cards[a-1][b-1] == '#')?'.':'#';

        for( int i = 0; i < n*2; i++ ) cout << cards[i] << endl;
    }
    return 0;
}
