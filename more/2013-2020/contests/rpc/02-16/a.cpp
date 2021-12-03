#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii; 

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define TRmsi(c, it) for (msi::iterator it = (c).begin(); it != (c).end(); it++)

ll n, d, x, y, ans;
long double dp, dt;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  cin >> n;
  while (n--) {
    cin >> d >> x >> y;
    dp = sqrt(d);
    dt = sqrt(x*x + y*y);

    if (dt/dp - floor(dt/dp) < 1e-9) ans = dt / dp;
    else if (dt > dp) ans = floor(dt / dp) + 1;
    else ans = 2; 
    cout << ans << endl;
  }
  return 0;
}

