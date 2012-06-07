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
ll N, Q, a, b, k, h;
vector<int> graph[100000];
int paths[100000];
int BlackWhite[100000];

void color( ll b ){
    BlackWhite[b] = ( !BlackWhite[b] )? 1 : 0 ;
}

ll solve( ll a ){
    ll cont = 1;
    while( cont != -1 ){
        if( BlackWhite[cont] == 1 ) return cont;
        else cont = paths[cont];
    }
    return -1;
}

void dfs( ll a ){
    ll here = a, ant = -1;
    stack<int> q;
    q.push( here );
    paths[a] = ant;

    while( q.size() ){
        ll first = q.top();
        q.pop();
        //if( first == 1 ) break;
        ant = first;
        for ( int i = 0; i< graph[first].size(); ++i ) {
            if( paths[ graph[first][i] ] == 0 ){
                paths[ graph[first][i] ] = ant;
                q.push( graph[first][i] );
            }
        }
    }
}

int main(){
  while( cin >> N >> Q ){
    For(r,0,N+3){
        paths[r] = BlackWhite[r] = 0;
        graph[r].clear();
    }
    for ( int i = 0; i< N-1; ++i ) {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for ( int j = 0; j < Q ; ++j ) {
        cin >> k >> h;
        if( k == 0 ) color( h );
        else{
            For(r,0,N+3) paths[r] = 0;
            dfs( h );
            cout << solve( h ) << endl;
        }
    }
  }
  return 0;
}
