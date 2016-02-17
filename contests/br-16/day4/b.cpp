#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii; 

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define TRmsi(c, it) for (msi::iterator it = (c).begin(); it != (c).end(); it++)

string s;
int carry, n, temp, ans, forward, back;
vector<int> pos;

int main() {
  freopen("bad.in", "r", stdin);
  freopen("bad.out", "w", stdout);
  cin >> s;
  REP(i, 0, s.size() - 1) {
    if (s[i] == '1') pos.push_back(i);
  }
  n = s.size();

  carry = 1 << 30;
  if (pos.size()) {
    carry = min(pos[pos.size() - 1], n - pos[0]);
    if (s.size() > 1) {
      REP(i, 0 , pos.size() - 1) {
        forward = 2 * pos[i] + (n - pos[(i + 1 + pos.size()) % pos.size()]);
        back = 2 * (n - pos[i]) + pos[(i - 1 + pos.size()) % pos.size()];
        carry = min(carry, min(back, forward));
      }
    }
  }
  ans = (carry == 1<<30) ? 0 : carry * 7 + 4 * pos.size();
  cout << ans << endl;
  return 0;
}

