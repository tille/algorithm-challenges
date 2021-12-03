#include <bits/stdc++.h>

using namespace std;

const int maxn = 1005;

typedef pair<int, int> ii;

vector<int> g[maxn];
vector<int> gt[maxn];
vector<bool> seen;
vector<int> toposort;
vector<ii> topo;

void dfs(int u) {
    seen[u] = true;
    for (auto v : g[u])
        if (!seen[v]) dfs(v);
    toposort.push_back(u);
}

void dfs2(int u, int deep) {
    seen[u] = true;
    for (auto v : gt[u]) {
        int vv = toposort[v];
        if (!seen[vv]) dfs2(vv, deep + 1);
    }
    topo.push_back({deep, u});
}

int main() {
    int t, n, r, r1, r2;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        cin >> n >> r;

        toposort.clear();
        topo.clear();
        seen.assign(n, false);
        for (int j = 0; j <= n; ++j) {
            g[j].clear();
            gt[j].clear();
        }

        while (r--) {
            cin >> r1 >> r2;
            g[r2].push_back(r1);
        }

        for (int j = 0; j < n; ++j) {
            if (!seen[j]) {
                dfs(j);
            }
        }
        
        reverse(toposort.begin(), toposort.end());
        vector<int> pos(n);

        for (int v = 0; v < toposort.size(); ++v) {
            int x = toposort[v];
            pos[x] = v;
        }

        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < g[j].size(); ++k) {
                int v = pos[ g[j][k] ];
                gt[j].push_back(v);
            }
            sort(gt[j].begin(), gt[j].end());
        }

        seen.assign(n, false);
        for (int j = 0; j < n; ++j) {
            if (!seen[j]) {
                dfs2(j, 1);
            }
        }

        reverse(topo.begin(), topo.end());
        sort(topo.begin(), topo.end());
        printf("Scenario #%d:\n", i);
        for (ii j : topo) {
            printf("%d %d\n", j.first, j.second);
        }
    }
    return 0;
}