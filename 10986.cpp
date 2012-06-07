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


struct edge{
    int to, weight;
    edge(){}
    edge(  int v, int w ): to(v), weight(w){}
    bool operator < ( const edge &that ) const{
        return weight > that.weight;
    }
};


typedef long long ll;
vector<edge> nodes[20005];
long paths[20005];
int visited[20005];
int t1, n, m, s, t2, a1, b1, c1;


int dijkstra( int a, int b ){
    priority_queue<edge> q;
    q.push( edge( a, 0 ) );

    while( q.size() ){
        int here = q.top().to;
        int weight = q.top().weight;
        q.pop();
        if( !visited[here] ){
            paths[here] = weight;
            visited[here] = 1;
            if( here == b ) return weight;
            for( int i = 0; i < nodes[here].size(); ++i ){
                int t = nodes[here][i].to;
                long w = nodes[here][i].weight;
                if( visited[ t ] == 0 ) q.push( edge( t , w+weight ) );
            }
        }
    }
    return 1<<13;
}


int main(){
  cin >> t1;
  int caso = 1;
  while( t1-- ){
    scanf("%d %d %d %d",&n, &m, &s, &t2);
    For(r,0,n+3) nodes[r].clear(), visited[r] = paths[r] = 0;
    for ( int i = 0; i< m; ++i ) {
        cin >> a1 >> b1 >> c1;
        nodes[a1].push_back( edge(b1,c1) );
        nodes[b1].push_back( edge(a1,c1) );
    }
    long tales = ( dijkstra(s,t2) );
    if( tales == 1<<13 ) printf("Case #%d: unreachable\n",caso++);
    else printf("Case #%d: %d\n",caso++, tales);
  }
  return 0;
}
