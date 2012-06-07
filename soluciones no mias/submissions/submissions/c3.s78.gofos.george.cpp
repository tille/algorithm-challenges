// Andrés Mejía
using namespace std;
#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
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

////////////// Prewritten code follows. Look down for solution. ////////////////
#define foreach(x, v) for (typeof (v).begin() x=(v).begin(); x !=(v).end(); ++x)
#define For(i, a, b) for (int i=(a); i<(b); ++i)
#define D(x) cout << #x " is " << (x) << endl

const double EPS = 1e-9;
int cmp(double x, double y = 0, double tol = EPS) {
    return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}
////////////////////////// Solution starts below. //////////////////////////////

const int MAXN = 1010;
vector<int> adj[MAXN];
int weight[MAXN][MAXN];
pair<int, int> closed[MAXN][MAXN];

vector<int> route;

int dist[MAXN];

const int oo = 1 << 30;

inline bool cerrada(int u, int v, int t) {
    return closed[u][v].first <= t and t <= closed[u][v].second;
}

int tiempoEspera(int u, int v, int t) {
    assert(cerrada(u, v, t));
    return closed[u][v].second - t + 1;
}

int dijkstra(int start, int finish, int t0, int N) {
    for (int i = 1; i <= N; ++i) {
        dist[i] = oo;
    }
    dist[start] = t0;
    priority_queue< pair<int, int>, vector<pair<int, int> >, greater< pair<int, int> > > q;
    q.push( make_pair(t0, start) );
    
    while (q.size() > 0) {
        int u = q.top().second;
        int w = q.top().first;
        q.pop();
        
        //printf("popped %d, %d\n", u, w);
        
        if (u == finish) return dist[u];
        if (w > dist[u]) continue;
        
        for (int k = 0; k < adj[u].size(); ++k) {
            int v = adj[u][k];
            int w_extra = weight[u][v];
            
            if (cerrada(u, v, w)) {
                w_extra += tiempoEspera(u, v, w);
            }
            
            if (w + w_extra < dist[v]) {
                dist[v] = w + w_extra;
                q.push(  make_pair( dist[v],  v )  );
            }
        }
    }
    assert(false);
}

int main(){
    int N, M;
    scanf("%d %d", &N, &M);
    int start, finish, t0, routeLength;
    scanf("%d %d %d %d", &start, &finish, &t0 ,&routeLength);
    
    route.resize(routeLength);
    for (int i = 0; i < routeLength; ++i) {
        scanf("%d", &route[i]);
    }
    
    for (int k = 0; k < M; ++k) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        adj[u].push_back(v);
        adj[v].push_back(u);
        weight[u][v] = weight[v][u] = w;
    }
    
    for (int i = 0; i <= N; ++i) {
        for (int j = i; j <= N; ++j) {
            closed[i][j] = closed[j][i] = make_pair(-1, -1);
        }
    }
    
    for (int i = 0, t = 0; i + 1 < routeLength; ++i) {
        int u = route[i];
        int v = route[i + 1];
        closed[u][v] = closed[v][u] = make_pair(t, t + weight[u][v] - 1);
        t += weight[u][v];
    }
    
    // for (int i = 1; i <= N; ++i) {
    //     for (int j = 1; j <= N; ++j) {
    //         printf("closed[%d][%d] = %d hasta %d\n", i, j, closed[i][j].first, closed[i][j].second);
    //     }
    // }
    
    int ans = dijkstra(start, finish, t0, N) - t0;
    printf("%d\n", ans);
    return 0;
}