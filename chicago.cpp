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
    int to;
    double weight;
    edge(){}
    edge( int t1, double w ) : to(t1) , weight(w){}
    bool operator < ( const edge &that ) const {
        return weight < that.weight;
    }
};


vector<edge> graph[110];
int visited[110];
double paths[110];
int n, m, a, b, p;


double dijkstra( int a, int b ){
    priority_queue<edge> q;
    q.push( edge(a,1.0) );

    while( q.size() ){
        int here = q.top().to;
        double weight = (double)q.top().weight;
        q.pop();
        if( !visited[here] ){
            visited[here] = 1;
            paths[here] = weight;
            if( here == b ) return weight;
            for( int i = 0; i < graph[here].size(); ++i ){
                int t = graph[here][i].to;
                double f = (double)graph[here][i].weight;
                double tales = (double)f*weight;
                if( !visited[t] ) q.push( edge( t, tales ) );
            }
        }
    }

    return paths[b];
}


int main(){
  while( cin >> n && n ){
    For(r,0,n+2){ graph[r].clear(); visited[r] = paths[r] = 0; }
    cin >> m;
    for( int i = 0; i < m; ++i ){
        cin >> a >> b >> p;
        double h = (double)p/100;
        graph[a].push_back( edge(b,h) );
        graph[b].push_back( edge(a,h) );
    }

    printf("%.6f percent\n",dijkstra( 1, n )*100);

  }

  return 0;
}
