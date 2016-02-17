#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii; 

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define TRmsi(c, it) for (msi::iterator it = (c).begin(); it != (c).end(); it++)

int t, n, m, pi, c, x, y, id;
char d;
int p[10005];
vector<int> power;

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
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  cin >> t;
  while (t--) {
    power.clear();
    cin >> n >> m >> pi >> c;

    init(n * m);

    while (pi--) {
      cin >> x >> y;
      id = (y * n) + x;
      power.push_back(id);
    }

    while (c--) {
      cin >> x >> y >> d;
      id = (y * n) + x;
      if (d == 'R') link(id, id + 1);
      else if (d == 'U') link(id, id + n);
    }

    vector<bool> conn(n * m, false);
    REP(i, 0, power.size() - 1) {
      conn[find(power[i])] = true;
    }
    
    int ans = 0;
    vector<bool> seen(n * m, false);
    REP(i, 0, (n * m) - 1) {
      int box = find(i);
      if (!seen[box]) {
        seen[box] = true;
        if (!conn[box]) ans++;
      }
    }

    cout << ans << endl;
  }
  return 0;
}

