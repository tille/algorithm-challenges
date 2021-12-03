#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii; 

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define TRmsi(c, it) for (msi::iterator it = (c).begin(); it != (c).end(); it++)

ll t, num;

int c_pot(int u, int v) {
  int res = 1;
  while (v--) res *= u;
  return res;
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  cin >> t;

  while (t--) {
    cin >> num;
    ll _s = c_pot(2, log2(num));
    ll sum_pot = (_s << 1) - 1;
    ll gauss = num * (num + 1) / 2;
    cout << gauss - (2 * sum_pot) << endl;
  }
  return 0;
}

