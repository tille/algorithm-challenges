#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii; 

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define TRmsi(c, it) for (msi::iterator it = (c).begin(); it != (c).end(); it++)

ll t, n, p, minor, cur, ans, g, d;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  cin >> t;
  while (t--) {
    cin >> n;

    p = 0;
    minor = 1<<30;
    REP(i, 1, n) {
      cin >> g >> d;
      cur = p + g - d;
      if (cur < minor) {
        minor = cur;
        ans = (i + 1 + n) % n;
      }
      p = cur;
    }

    if (cur >= 0) cout << ans << endl;
    else cout << "IMPOSSIBLE" << endl;
  }
  return 0;
}

