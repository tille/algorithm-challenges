#include <bits/stdc++.h>

using namespace std;

const int maxn = 1005;

vector<int> toposort;
vector<int> g[maxn];
vector<bool> seen;

int dfs(int u) {
    seen[u] = true;
    for (int v : g[u])
        if (!seen[v]) dfs(v);
    toposort.push_back(u); 
}

int main() {
    int nodos, aristas;
    cin >> nodos >> aristas;

    seen.assign(nodos, false);
    toposort.clear();

    int u, v;
    for (int i = 0; i < aristas; ++i) {
        cin >> u >> v;
        g[u].push_back(v);
    }

    for(int i = 0; i < nodos; ++i)
        if (seen[i] == false) dfs(i);

    reverse(toposort.begin(), toposort.end());

    for (int i = 0; i < toposort.size(); ++i)
        cout << toposort[i] << " ";
    cout << endl;

    return 0;
}