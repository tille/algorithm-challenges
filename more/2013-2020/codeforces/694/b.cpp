#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

const int inf = 1<<30;

int dr[] = {1,-1,0, 0,1,-1,-1, 1};
int dc[] = {0, 0,1,-1,1, 1,-1,-1};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  int t;
  cin >> t;
  while (t--) {
    int n, x;
    bool repeat = true;
    ll ans = 0;
    cin >> n >> x;

    vi v(n);
    vi cnt(n, 1);
    for (auto &a : v) {
      cin >> a;
      ans += a;
    }
    while (repeat) {
      REP(i, 0, n-1) {
        if (v[i] % x == 0) {
          v[i] = v[i] / x;
          cnt[i] *= x;
          ans += v[i] * cnt[i];
        } else {
          repeat = false;
          break;
        }
      }
    }
    cout << ans << endl;

  }

  return 0;
}