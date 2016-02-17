#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii; 

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define TRmsi(c, it) for (msi::iterator it = (c).begin(); it != (c).end(); it++)

int n;
string ans;
vector<int> luckys[4];

int almost(int lucky) {
  return 0;
}

int c_pot(int n, int x) {
  int res = 1;
  while (x--) res *= n;
  return res;
}

int main() {
  cin >> n;
  // generate all lucky numbers with 3 digits
  luckys[0].push_back(0);
  REP(i, 1, 3) {
    REP(j, 0, luckys[i - 1].size() - 1) {
      luckys[i].push_back(4 * c_pot(10, i - 1) + luckys[i - 1][j]);
      luckys[i].push_back(7 * c_pot(10, i - 1) + luckys[i - 1][j]);
    }
  }

  ans = "NO";
  REP(i, 1, 3) {
    REP(j, 0, luckys[i].size() - 1) {
      if (n % luckys[i][j] == 0) {
        ans = "YES";
        break;
      }
    }
    if (ans == "YES") break;
  }
  cout << ans << "\n";
  return 0;
}

