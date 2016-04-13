#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii; 

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define TRmsi(c, it) for (msi::iterator it = (c).begin(); it != (c).end(); it++)

int a, b, ans;

bool check(int n) {
  vector<int> vis(10, 0);
  while (n) {
    if (vis[n % 10]) return false;
    else {
      vis[n % 10] = 1;
      n /= 10; 
    }
  }
  return true;
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  while (cin >> a >> b) {
    ans = 0;
    REP(i, a, b) if (check(i)) ans += 1;
    cout << ans << endl;
  }
  return 0;
}

