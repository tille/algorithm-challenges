#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii; 

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define TRmsi(c, it) for (msi::iterator it = (c).begin(); it != (c).end(); it++)

const int maxn = 100005;
ll n, k, levels;
string s, w, ans;
bool win[maxn], lose[maxn];

struct Trie {
  struct node {
    int c;
    int a[28];
  };

  node g[maxn];
  int stateCount;

  Trie() {
    stateCount = 0;
    clear();
  };

  void clear() {
    g[stateCount].c = 0;
    memset(g[stateCount].a, -1, sizeof g[stateCount].a);
    stateCount++;
  }

  void add(const string &s) {
    int cur = 0;
    REP(i, 0, s.size() - 1) {
      int next = s[i] - 'a';
      
      if (g[cur].a[next] == -1) { 
        g[cur].a[next] = stateCount; 
        clear(); 
      }
      cur = g[cur].a[next]; 
      g[cur].c += 1;
    }
  }
};
Trie t;

int dfs(int node) {
  win[node] = false;
  lose[node] = false;
  bool leaf = true;

  REP(i, 0, 27) {
    if (t.g[node].a[i] != -1) {
      leaf = false;
      int to = t.g[node].a[i];
      dfs(to);
      win[node] |= !win[to];
      lose[node] |= !lose[to];
    }
  }

  if (leaf) {
    lose[node] = true;
  }
}


int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  string p[2] = {"First", "Second"};

  cin >> n >> k;

  REP(i, 0, n - 1) {
    cin >> s;
    t.add(s);
  }
  dfs(0);

  if (!win[0]) ans = p[1];
  else if (lose[0]) ans = p[0];
  else if (!lose[0] && k % 2 == 1) ans = p[0];
  else ans = p[1];

  cout << ans << endl;
  return 0;
}
