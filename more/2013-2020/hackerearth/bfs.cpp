#include <bits/stdc++.h>
using namespace std;

#define maxn 10002
vector<int> g[maxn];

void bfs(int s, int n, int t) {
    vector<int> seen(maxn, -1);
    queue<int> q;
    q.push(s);
    seen[s] = 0;
    int ans = 0;
    
    while (q.size()) {
        int cur = q.front();
        q.pop();
        
        for (int to : g[cur]) {
            if (seen[to] == -1) {
                int dist = seen[cur] + 1;
                if (dist == t) ans++;
                seen[to] = dist;
                q.push(to);
            }
        }
    }

    // for (int i = 0; i <= n; ++i) 
    //     cout << i << " " << seen[i] << endl;

    cout << ans << endl;
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        g[u].push_back(v);
        g[v].push_back(u);
    }

    int queries, s, t;
    cin >> queries;

    // for (int i = 0; i <= n; ++i) {
    //     cout << "i " << i << ": ";
    //     for (int x : g[i]) {
    //         cout << x << ' ';
    //     }
    //     cout << endl;
    // }

    while (queries--) {
        cin >> s >> t;
        bfs(s, n, t);
    }

    
    return 0;
}