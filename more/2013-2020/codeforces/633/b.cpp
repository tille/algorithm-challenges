#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii; 

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define TRmsi(c, it) for (msi::iterator it = (c).begin(); it != (c).end(); it++)

vector<int> ans;
int m;

ll r(int n) {
  ll res = 0;
  for (int i = 5; i <= n; i *= 5)
    res += int(n / i);
  return res;
}

void precalc(int n) {
  for (int i = 0; true; ++i) {
    int zeros = r(i);
    if (zeros > m) break;
    if (zeros == m) ans.push_back(i);
  }
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  cin >> m; 
  precalc(m);

  cout << ans.size() << endl;
  REP(j, 0, ans.size() - 2)
    cout << ans[j] << " ";
  if (ans.size()) 
    cout << ans[ans.size() - 1] << endl;

  return 0;
}

