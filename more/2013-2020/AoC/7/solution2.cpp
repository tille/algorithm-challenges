#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

const int inf = 1<<30;

int dr[] = {1,-1,0, 0,1,-1,-1, 1};
int dc[] = {0, 0,1,-1,1, 1,-1,-1};

int const MAXN = 100000;
int ans = 0;
vector<pair<int, int> > g[MAXN];
// vector<bool> visited(MAXN, 0);
bool visited[MAXN];
map<string, int> m;
map<int, string> rm;

// int dfs3(int u) {
//   visited[u] = true;
//   ans++;
//   for (int v: g[u]) {
//     if (!visited[v]) {
//       dfs3(v);
//     }
//   }
// }

// int dfs2(int u) {
//   stack<int> s;
//   s.push(u);
//   ans = 0;

//   while (s.size()) {
//     int cur = s.top();
//     cout << rm[cur] << endl;
//     s.pop();

//     for (int v: g[cur]) {
//       if (!visited[v]) {
//         visited[v] = true;
//         ans++;
//         s.push(v);
//       }
//     }
//   }

//   return ans;
// }

int dfs(int u) {
  int ans = 1;
  if (!g[u].size()) return 1;

  for (ii e: g[u]) {
    ans += (e.first * dfs(e.second));
  }
  return ans;
}


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  string line, s1, s2, x, name;
  int idx = 0, cant;

  while(getline(cin, line)) {
    stringstream ss(line);

    ss >> s1 >> s2 >> x;
     assert(x=="bags");
    name = s1 + " " + s2;

    if (!m.count(name)) {
      rm[idx] = name;
      m[name] = idx++;
    }
    int cur = m[name];
    
    ss >> x;
    // cout << cur << ": ";
    while (ss >> cant >> s1 >> s2 >> x) {
      name = s1 + " " + s2;
      if (!m.count(name)) {
        rm[idx] = name;
        m[name] = idx++;
      }
      // cout << m[name] << " ";
      g[cur].pb(make_pair(cant, m[name]));
    }


    // cout << endl;
  }
  int ini = m["shiny gold"];
  cout << dfs(ini) - 1 << endl;
  // cout << ans - 1 << endl;
  // cout << dfs2(ini) << endl;


  // map<string, int>::iterator it;
  // for (int i = 0; i < idx; ++i) {
  //   cout << rm[i] << ": ";
  //   for (int j = 0; j < g[i].size(); ++j) {
  //     pair<int, int> v = g[i][j];
  //     cout << rm[v.second] << " ";
  //   }
  //   cout << endl;
  // }
  return 0;
}