#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii; 

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define TRmsi(c, it) for (msi::iterator it = (c).begin(); it != (c).end(); it++)

int n, q, s, t;
int p[100005];

void init(int n){
  for(int i = 0; i < n; ++i) p[i] = i;
}

int find(int u){
  return p[u] == u ? u : p[u] = find(p[u]);
}

void link(int u, int v){
  int a = find(u);
  int b = find(v);
  if (a != b) p[a] = b;
}

int main() {
  scanf("%d%d", &n, &q);
  init(n + 1);

  while (q--) {
    scanf("%d%d", &s, &t);
    link(s, t);
  }

  REP(i, 1, n - 1) 
    printf("%d ", find(i)); 

  printf("%d\n", find(n));

  return 0;
}

