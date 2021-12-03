#include <bits/stdc++.h>

using namespace std;

int n, m, sol;
int me[10005], mw[10005];
char SQ[105][10005];
int ne, nw, idx, acum, min_e; 

int main () {
  me[0] = 0;
  sol = 1 << 30;  
  ne = nw = 0;
  cin >> n >> m;
  mw[n] = mw[n + 1] = 0;

  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> SQ[i][j];

      if (SQ[i][j] == 'W') nw++;
      else ne++;
    }
  }

  for (int i = 0; i < n; ++i) {
    acum = 0;
    for (int j = 0; j < m; ++j)
      if (SQ[j][i] == 'E') acum++;
    me[i + 1] = me[i] + acum;
  }

  for (int i = n - 1; i >= 0; --i) {
    acum = 0;
    for (int j = 0; j < m; ++j)
      if (SQ[j][i] == 'W') acum++;
    mw[i] = mw[i + 1] + acum;
  }

  if (nw == n*m) idx = n;
  else if (ne == n*m) idx = 0;
  else {
    for (int i = 1; i < n; ++i) {
      min_e = me[i] + mw[i];
      if (min_e < sol) {
        sol = min_e;
        idx = i; } }
  }

  cout << idx << " " << idx + 1 << endl;
  return 0;
}
