#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii; 

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define TRmsi(c, it) for (msi::iterator it = (c).begin(); it != (c).end(); it++)

int f[200005][2];
int c;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  string a, b;
  cin >> a >> b;

  f[0][0] = f[1][0] = 0;
  REP(i, 1, b.size()) {
    c = b[i - 1] - '0';
    f[i][0] = f[i-1][0];
    f[i][1] = f[i-1][1];
    f[i][c]++;
  }

  ll ans = 0;
  REP(i, 0, a.size() - 1) {
    REP(j, 0, 1) {
      ans += abs((a[i] - '0') - j) * (f[b.size() - a.size() + i + 1][j] - f[i][j]);
    }
  }
  cout << ans << endl;
  return 0;
}

