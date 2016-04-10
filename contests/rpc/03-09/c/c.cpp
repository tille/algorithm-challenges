#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii; 

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define TRmsi(c, it) for (msi::iterator it = (c).begin(); it != (c).end(); it++)

int a[100005];
int cnt[100005][10];

int main() {
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL);
  int n, m, l, r;

  while (cin >> n) {
    REP(i, 0, 9) cnt[0][i] = 0;

    REP(i, 1, n) {
      cin >> a[i];
      REP(j, 0, 9) cnt[i][j] = cnt[i - 1][j];
      cnt[i][a[i]]++;
    }

    cin >> m;
    while (m--) {
      cin >> l >> r;
      int ans = 0;
      REP(j, 0, 9) {
        if (cnt[r][j] - cnt[l - 1][j] > 0) {
          ans += 1;
        }
      }
      cout << ans << endl;
    }
  }
  return 0;
}

