// problem: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=&problem=3354&mosmsg=Submission+received+with+ID+16167769

#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

#define MAXN 1000

struct edge { 
  int to, weight;
  edge(){};

  edge(int next_node, int edge_weight) { 
    to = next_node;
    weight = edge_weight;
  }
};

int gravestones_count; // number of gravestones in the current graveyard
int dist[MAXN];
// int previ[MAXN];
int gravestones[MAXN][MAXN];
vector<edge> g[MAXN];

bool update_dist(int n) {
  bool updated = false;

  for (int u = 0; u < n; ++u) {
    for (int v = 0; v < g[u].size(); ++v) {
      int next = g[u][v].to;
      int weight = g[u][v].weight;

      if(dist[u] >= 1<<30) continue;

      // if (dist[next] > dist[u] + weigth) prev[next] = u;
      if (dist[next] > dist[u] + weight) {
        dist[next] = dist[u] + weight;
        updated = true;
      }
    }
  }
  return updated;
}

// receives 'start' and number and of nodes in the graph
void bellman_ford(int s, int n) {
  for (int u = 0; u <= n; ++u) {
    dist[u] = 1<<30;
    // previ[u] = -1;
  }

  dist[s] = 0;
  int tales = n-gravestones_count-1; // size of graveyard minus gravestones

  while (tales--)
    update_dist(n);
}

bool verify(int i, int j, int w, int h, int test_case) {
  bool valid_edge = false;

  if (i>=0 && j>=0 && i<w && j<h && gravestones[i][j] != test_case)
    valid_edge = true;

  return valid_edge;
}

void create_graph(int w, int h, int test_case) {
  for (int i = 0; i < w; ++i) {
    for (int j = 0; j < h; ++j) {
      int node = i*h + j;
      g[node].clear();

      if (gravestones[i][j] != test_case && node != w*h-1) {
        // verify top, left, right, down and push each one if valid
        if (verify(i-1, j, w, h, test_case)) g[node].push_back( edge((i-1)*h+j, 1) );
        if (verify(i+1, j, w, h, test_case)) g[node].push_back( edge((i+1)*h+j, 1) );
        if (verify(i, j+1, w, h, test_case)) g[node].push_back( edge(i*h+(j+1), 1) );
        if (verify(i, j-1, w, h, test_case)) g[node].push_back( edge(i*h+(j-1), 1) );
      }
    }
  }
}

int main() { 
  int w, h, n, gr, x, y, E, x1, y1, x2, y2, t, test_case = 1;

  while (cin >> w >> h && w+h != 0) {
    n = w*h; // number of nodes

    cin >> gr;
    gravestones_count = gr;

    while (gr--) {
      cin >> x >> y;
      gravestones[x][y] = test_case;
    }

    create_graph(w, h, test_case);

    cin >> E; // number of haunted holes

    vector<int> machetazo; // al final uno se cansa y hace estas cosas.

    while (E--) {
      cin >> x1 >> y1 >> x2 >> y2 >> t;
      int node = x1*h + y1;
      int next = x2*h + y2;

      machetazo.push_back(node);
      machetazo.push_back(next);
      machetazo.push_back(t);
      g[node].clear();
    }

    for (int i = 0; i < machetazo.size(); i+=3) {
      g[machetazo[i]].push_back( edge(machetazo[i+1], machetazo[i+2]) );
    }

    bellman_ford(0, n);
    int result = dist[n-1];

    if (update_dist(n)) 
      cout << "Never" << endl;
    else {
      if (result >= 1<<30)
        cout << "Impossible" << endl;
      else
        cout << result << endl;
    }

    test_case++;
  }

  return 0;
}

// Este problema se resuelve usando el algoritmo de bellman-ford 
// sin embargo tiene 2 trucos
// 1) el numero de nodos validos no es w*h en realidad es w*h-gravestones
// 2) en caso de caer en un haunted hole esta obligado a tomar ese camino y NO puede evitarlo y seguir caminando
// pero puede decidir cual tomar entre los haunted hole que esten en esa posicion.
