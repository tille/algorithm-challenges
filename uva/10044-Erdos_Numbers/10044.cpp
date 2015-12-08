#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii; 
typedef set<int> si; 
typedef map<string, int> msi;

#define REP(i, a, b) \
  for (int i = int(a); i <= int(b); i++)
#define TRmsi(c, it) \
  for (si::iterator it = (c).begin(); it != (c).end(); it++)
#define MAXN 10000

int t, p, n, cont;
string line, name, surname, author;
vector<int> v;
msi authors;
si g[MAXN];
int visited[MAXN];
int sol[MAXN];

void bfs(int start, int mark) {
  queue<ii> q;
  q.push( make_pair(start, mark) );

  while (q.size()) {
    int cur = q.front().first;
    mark = q.front().second;
    q.pop();

    if (visited[cur]) continue;
    visited[cur] = 1;
    sol[cur] = mark;

    TRmsi(g[cur], next)
      if (!visited[*next])
        q.push( make_pair(*next, sol[cur] + 1) );
  }
}

void clear_all() {
  authors.clear(); cont = 0;
  REP(j, 0, MAXN - 2) {
    visited[j] = 0;
    sol[j] = -1;
    g[j].clear();
  }
}

int line_pos;
string next_author() {
  int cant = 0, idx;
  while (true) {
    cant++; idx = line_pos + cant;
    if ( (line[idx] == '.' && (idx + 1) < (line.size() - 1) && line[idx + 1] == ',') || line[idx] == ':') {
      string ans = line.substr(line_pos, cant);
      line_pos = (line[idx] == ':') ? -1 : line_pos + cant + 3;
      return ans;
    }
  }
}

int main() {
  scanf("%d", &t);
  REP(i, 0, t - 1) {
    clear_all();
    cin >> p >> n;
    getline(cin, line); // read endline

    REP(j, 0, p - 1) {
      v.clear();
      // read authors and assign ids for them
      getline(cin, line);
      line_pos = 0;

      do {
        author = next_author();
        if (authors.count(author) == 0) authors[author] = cont++;
        v.push_back(authors[author]);
        if (line_pos == -1) break;
      } while (true);

      // create graph
      REP(k, 0, v.size() - 1) REP(r, 0, v.size() - 1) {
        if (k == r) continue;
        g[v[k]].insert(v[r]);
        g[v[r]].insert(v[k]);
      }
    }
    bfs(authors["Erdos, P."], 0);

    // REP(k, 0, cont - 1) {
    //   cout << k << ": "; 
    //   TRmsi(g[k], it) {
    //     cout << (*it) << " ";
    //   }
    //   cout << endl;
    // }
    // REP(j, 0, cont - 1)
    //   cout << sol[j] << endl;

    cout << "Scenario " << i + 1 << endl;
    REP(j, 0, n - 1) {
      getline(cin, name);
      cout << name << " ";
      int mark = sol[authors[name]];
      if (mark == -1) cout << "infinity" << endl;
      else cout << mark << endl;
    }
  }
  return 0;
}
