#include <bits/stdc++.h>
using namespace std;
#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)

int t, n, l, p; 
string ans, s; 
map<char, int> f; 
int nxt[100005];

int next(int u) {
  int fwd = nxt[u];
  return (fwd < n && f[s[fwd]] <= 0) ? nxt[u] = next(fwd) : fwd;
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  // cin >> t;
  while (cin >> s) {
    sort(s.begin(), s.end());

    n = s.size(); ans = ""; f.clear();
    int repeated = 0; 

    REP(i, 0, n - 1) {
      f[s[i]]++;
      repeated = max(repeated, f[s[i]]);
    }

    if (repeated > (s.size() - repeated + 1)) {
      cout << "IMPOSSIBLE" << endl;
      continue;
    }

    nxt[n - 1] = n;
    for (int i = n - 2; i >= 0; --i) {
      if (s[i] != s[i + 1]) nxt[i] = i + 1;
      else nxt[i] = nxt[i + 1];
    }

    l = 1; p = s[0]; ans += p; f[p]--; 

    while (ans.size() != n) {
      if (f[s[l]]) {
        if (s[l] == ans[ans.size() - 1]) {
          if (next(l) == n) break;
          ans += s[next(l)];
          f[s[next(l)]]--;
        }
        ans += s[l];
        f[s[l]]--;
      } else l = next(l);
    }

    if (ans.size() == s.size()) {
      cout << ans << endl;
      continue;
    }

    string res = ""; 
    res += ans[ans.size() - 1];
    l = ans.size() - 2;

    while (res.size() != s.size() && l >= 0) {
      if (f[s[ans.size() - 1]]) {
        if (res[res.size() - 1] != ans[ans.size() - 1] && ans[l] != ans[ans.size() - 1]) {
          res += ans[ans.size() - 1];
          f[ans[ans.size() - 1]]--;
        }
      }
      res += ans[l];
      l--;
    }

    if (f[s[ans.size() - 1]]) res += ans[ans.size() - 1];
    reverse(res.begin(), res.end());
    cout << res << endl;

  }
  return 0;
}

