#include <stdc++.h>

using namespace std;

#define MAXN 13

int matriz[MAXN][MAXN];
vector<int> g[MAXN];

void clear() {
  // limpia grafo (lista de adyacencia)
  for(int i = 0; i < MAXN; i++) {
    g[i].clear();
  }

  // limpia la matriz
  for(int i = 0; i < MAXN; i++) {
    for(int j = 0; j < MAXN; j++) {
      matriz[i][j] = 0;
    }
  }
}

int main() {
  int n, m, u, v;

  while( cin >> n >> m ) {
    clear();

    while (m--) {
      cin >> u >> v;

      g[u].push_back(v); // llena la lista de adyacencia
      matriz[u][v] = 1; // llena la matriz
    }
  }

  return 0;
}
