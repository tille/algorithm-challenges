#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii; 

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define TRmsi(c, it) for (msi::iterator it = (c).begin(); it != (c).end(); it++)

int n[105];
int ans[105];
int p[105][10];
bool solved[105][10];

int c, _p, t;
char r;
vector<int> pjs;

bool sorting(int u, int v) {
  if (n[u] > n[v] || (n[u] == n[v] && ans[u] < ans[v]) || (n[u] == n[v] && ans[u] == ans[v] && u < v)) {
    return true;
  }
  return false;
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  string line;
  int cases;

  cin >> cases;
  getline(cin, line);
  getline(cin, line);

  while (cases--) {
    pjs.clear();
    REP(cc, 0, 101) {
      n[cc] = 0;
      ans[cc] = 0;
      REP(j, 0, 9) {
        p[cc][j] = 0;
        solved[cc][j] = false;
      }
    }

    while (getline(cin,line) && line.size()) {
      stringstream ss(line);
      ss >> c >> _p >> t >> r;

      if (r == 'C' && !solved[c][_p]) {
        p[c][_p] += t;
        solved[c][_p] = true;
        n[c]++;
        ans[c] += p[c][_p];
      } else if (r == 'I' && !solved[c][_p]) {
        p[c][_p] += 20;
      }

      if (find(pjs.begin(), pjs.end(), c) == pjs.end()) pjs.push_back(c);
    }

    sort(pjs.begin(), pjs.end(), sorting); 

    REP(i, 0, pjs.size() - 1) {
      int ci = pjs[i];
      cout << ci << " " << n[ci] << " " << ans[ci] << endl;
    }

    if (cases > 0) cout << endl;
  }
  return 0;
}
