#include <bits/stdc++.h>
using namespace std;

#define maxn 1002
vector<int> g[maxn];

void bfs(int s, int n) {
    vector<int> seen(n, -1);
    queue<int> q;
    q.push(s);
    seen[s] = 0;
    
    while (q.size()) {
        int cur = q.front();
        q.pop();
        
        for (int i = 0; i < g[cur].size(); ++i) {
            int to = g[cur][i];
            if (seen[to] == -1) {
                seen[to] = seen[cur] + 6;
                q.push(to);
            }
        }
    }
    
    for(int i = 0; i < n; ++i) {
        if (i != s)
            cout << seen[i] << ' ';
    }
    cout << endl;
}

int main() {
    int queries;
    cin >> queries;
        
    while (queries--) {
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < n; ++i) g[i].clear();

        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            u--, v--;

            g[u].push_back(v);
            g[v].push_back(u);
        }

        int s;
        cin >> s;
        s--;

        bfs(s, n);
    }
    
    return 0;
}