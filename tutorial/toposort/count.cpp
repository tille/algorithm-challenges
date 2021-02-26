#include <bits/stdc++.h>

using namespace std;

vector<int> seen;

int dfs(int u) {
    seen[u] = true;
    for (v : g[u]) 
        if (!seen[v]) dfs(v);
    topo[u]++;
    seen[v] = false;
}

int main() {

        seen.assign(n, false);

        cin >> n >> r;

        while (r--) {
            cin >> r1 >> r2;
            g[r2].push_back(r1);
        }


    return 0;
}