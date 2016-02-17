#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii; 

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define TRmsi(c, it) for (msi::iterator it = (c).begin(); it != (c).end(); it++)

int diffs[1005];
int n, m, k;
int a[1005];

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  memset(diffs, 0, sizeof diffs);
  cin >> n >> m >> k;

  REP(i, 0, m) {
    cin >> a[i];
  }

  REP(i, 0, n - 1) {
    REP(j, 0, m - 1) {
      bool ff = a[j] & (1 << i); 
      bool me = a[m] & (1 << i);
      if (ff != me) diffs[j]++;
    }
  }

  int ans = 0;
  REP(i, 0, m - 1) {
    if (diffs[i] <= k) ans++;
  }

  cout << ans << endl;
  return 0;
}
