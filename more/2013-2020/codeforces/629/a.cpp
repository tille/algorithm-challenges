#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii; 

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define TRmsi(c, it) for (msi::iterator it = (c).begin(); it != (c).end(); it++)

int n;
char m;
int r[105], c[105];

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  cin >> n; 
  memset(r, 0, sizeof r);
  memset(c, 0, sizeof c);

  REP(i, 0, n - 1) {
    REP(j, 0, n - 1) {
      cin >> m;
      if (m == 'C') {
        r[i]++;
        c[j]++;
      }
    }
  }

  ll ans = 0;
  REP(i, 0, n - 1) {
    ans += ((r[i] - 1) * (r[i])) / 2;
    ans += ((c[i] - 1) * (c[i])) / 2;
  }
  cout << ans << endl;

  return 0;
}

