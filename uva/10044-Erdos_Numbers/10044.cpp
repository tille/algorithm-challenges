#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii; 

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define TRmsi(c, it) for (msi::iterator it = (c).begin(); it != (c).end(); it++)

int t, p, n, aa;
string line;
vector<int> g[1000000];
map<string, int> pos;
set<ii> vis;
int ans[1000000];

string format(const string &s) {
  int i = 0; int j = s.size() - 1;
  while (s[i] == ' ') i++;
  while (s[j] == ' ') j--;
  return s.substr(i, j - i + 1);
}

void add_graph(const string &s) {
  vector<string> authors;
  int p = 0, comma = 0;
  for (int i = 0; i < s.size(); ++i) {
    if (s[i] == ',') comma++;
    if (s[i] == ':' || comma == 2) {
      string author = format(s.substr(p, i - p));
      if (author.size()) {
        authors.push_back(author);
        if (!pos[author]) {
          // if (author == "Erdos, P.") cout << "fdsa" << endl;
          pos[author] = aa++;
        }
      }
      p = i + 1;
      comma = 0;
    }
  }

  REP(i, 0, authors.size() - 1) {
    int cur = pos[authors[i]];
    REP(j, i + 1, authors.size() - 1) {
      int to = pos[authors[j]];
      ii state = make_pair(to, cur);

      if (!vis.count(state)) {
        g[cur].push_back(to);
        g[to].push_back(cur);
        vis.insert(make_pair(cur, to));
        vis.insert(make_pair(to, cur));
      }
    }
  }
}

void bfs(int ini) {
  queue<ii> q;
  q.push(make_pair(ini, 0));

  while (q.size()) {
    int cur = q.front().first;
    int d = q.front().second;
    q.pop();

    if (ans[cur] == -1) {
      ans[cur] = d;
      for (int j = 0; j < g[cur].size(); ++j) {
        int to = g[cur][j];
        q.push(make_pair(to, d + 1));
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  cin >> t;
  aa = 1;

  REP(tc, 1, t) {
    cin >> p >> n;
    getline(cin, line);
    pos.clear();
    vis.clear();

    REP(i, 0, aa) {
      g[i].clear();
    }

    aa = 1;
    REP(i, 1, p) {
      getline(cin, line);
      add_graph(line);
    }

    REP(i, 0, aa) {
      ans[i] = -1;
    }
    // REP(i, 1, aa-1) {
    //   ans[i] = -1;
    //   REP(j, 0, g[i].size() - 1) {
    //     cout << g[i][j] << " ";
    //   }
    //   cout << endl;
    // }

    bfs(pos["Erdos, P."]);
    // cout << "blah: " << pos["Erdos, P."] << endl;
    // for(map<string,int>::iterator it = pos.begin(); it != pos.end(); ++it) {
    //   cout << it->first << "\n";
    // }

    // REP(i, 1, aa-1) {
    //   cout << ans[i] << endl;
    // }

    string author;
    cout << "Scenario " << tc << endl;
    REP(j, 1, n) {
      getline(cin, author);
      int dist = ans[pos[author]];
      if (dist != -1) {
        cout << author << " " << dist << endl;
      } else {
        cout << author << " " << "infinity" << endl;
      }
    }
  }
  return 0;
}

