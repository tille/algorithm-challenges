#include <bits/stdc++.h>

using namespace std;

const int maxn = 10002;

vector<int> topo;
vector<int> seen;
vector<int> g[maxn];
bool valid = true;

void dfs(int u) {
    seen[u] = 1;
    for (int v : g[u]) {
        if (seen[v] == 0) dfs(v);
        else if (seen[v] == 1) {
            valid = false;
            return;
        }
    }
    seen[u] = 2;
    topo.push_back(u);
}

int main() {
    int n, m;
    cin >> n >> m;

    seen.assign(n, 0);

    int x, y;
    while (m--) {
        cin >> x >> y;
        x--; y--;
        g[x].push_back(y);
    }

    for (int i; i < n; ++i)
        sort(g[i].rbegin(), g[i].rend());

    for (int i = n-1; i >= 0; --i)
        if (!seen[i]) dfs(i);

    if (!valid) {
        cout << "Sandro fails." << endl;
    } else {
        reverse(topo.begin(), topo.end());
        for (int i = 0; i < topo.size(); ++i) {
            cout << topo[i] + 1;
            if (i != topo.size() - 1) cout << " ";
        }
        cout << endl;
    }
    return 0;
}