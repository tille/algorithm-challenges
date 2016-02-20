#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii; 

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define TRmsi(c, it) for (msi::iterator it = (c).begin(); it != (c).end(); it++)

int n, l, r, ans, idx;
char c;
int m[2][405];

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  REP(i, 0, 400) { m[0][i] = m[1][i] = 0; }
  cin >> n;

  REP(i, 0, n - 1) {
    cin >> c >> l >> r;
    idx = (c == 'M') ? 0 : 1;
    REP(j, l, r) m[idx][j] += 1;
  }

  ans = 0;
  REP(j, 1, 366) {
    ans = max(ans, 2*min(m[0][j], m[1][j]));
  }
  cout << ans << endl;

  return 0;
}

