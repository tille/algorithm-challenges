#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii; 

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define TRmsi(c, it) for (msi::iterator it = (c).begin(); it != (c).end(); it++)

int n, t;
int a[100005];
ll ans;

int main() {
  cin >> n >> t;

  a[0] = 1;
  REP(i, 1, t) {
    cin >> a[i];

    if (a[i] >= a[i - 1])
      ans += a[i] - a[i - 1];
    else
      ans += n - a[i - 1] + a[i];
  }
  cout << ans << endl;
  return 0;
}

