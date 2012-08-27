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
typedef pair<int,int> way;

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }

template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }

#define For(i, a, b) for (int i=(a); i<(b); ++i)
#define D(x) cout << #x " es " << (x) << endl

int fuel[1005];
int visited[1005][1005];
vector<way> dist[1005];

struct node{
    int cty,g,cost;
    node() {}
    node(int t, int w, int iu) : cty(t), g(w), cost(iu) {}
    bool operator < (const node &that) const {
        return cost > that.cost;
    }
};

int dijkstra(int tam, int a, int b){

    memset(visited,0,sizeof visited);
    priority_queue<node> q;
    q.push( node(a,0,0) );

    while( q.size() ){
        int g = q.top().g;
        int cty = q.top().cty;
        int cost = q.top().cost;
        q.pop();

        if( !visited[cty][g] ){
            visited[cty][g] = 1;
            if( cty == b ) return cost;
            if( (g+1) <= tam && !visited[cty][g+1] ) q.push( node(cty,g+1,cost+fuel[cty]) );
            for( int i = 0; i <dist[cty].size(); ++i ){
                int temp1 = dist[cty][i].first;
                int temp2 = dist[cty][i].second;
                if( g>=temp2 && !visited[temp1][g-temp2] ) q.push( node(temp1,g-temp2,cost) );
            }
        }
    }
    return -1;
}

int main(){
    freopen("in.txt","r",stdin);
    int n,m,a,b,c,q,t,s,e;
	while( cin >> n >> m ){
        for( int i = 0; i<n; ++i ) scanf("%d",&fuel[i]), dist[i].clear();
        for( int i = 0; i<m; ++i ){
            cin >> a >> b >> c;
            dist[a].push_back( way(b,c) );
            dist[b].push_back( way(a,c) );
        }
        cin >> q;
        while( q-- ){
            cin >> t >> s >> e;
            int result = dijkstra(t,s,e);
            if( result == -1 ) cout << "impossible" << endl;
            else cout << result << endl;
        }
	}
    return 0;
}
