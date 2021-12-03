#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii; 

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define TRmsi(c, it) for (msi::iterator it = (c).begin(); it != (c).end(); it++)

priority_queue<int> q;

int c, n, tot, ans, taken;

int main() {
  cin >> c;
  while (c--) {
    cin >> n;
    tot += n;
    q.push(n);
  }

  ans = 0;
  while (q.size()) {
    ans++;
    n = q.top(); q.pop();
    taken += n;
    tot -= n;
    if (taken > tot) break;
  }
  cout << ans << "\n";
  return 0;
}

