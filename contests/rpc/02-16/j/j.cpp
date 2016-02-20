#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii; 

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define TRmsi(c, it) for (msi::iterator it = (c).begin(); it != (c).end(); it++)

int t, n, cur, to;
string s;
int nxt[1000005];
char p;
string ans;
map<char, int> f;

int next(int u) {
  int fwd = nxt[u];
  if (u >= n) return n;
  return (f[ s[fwd] ]) ? fwd : nxt[u] = next(fwd); 
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  cin >> t;

  while (t--) {
    cin >> s;
    f.clear();

    sort(s.begin(), s.end());
    n = s.size();

    nxt[n - 1] = n;
    f[s[s.size() - 1]]++;
    for (int i = n - 2; i >= 0; --i) {
      f[s[i]]++;
      if (s[i] != s[i + 1]) nxt[i] = i + 1;
      else nxt[i] = nxt[i + 1];
    }

    p = s[0];
    ans = ""; 
    ans += p;

    int i = 1, next_i;
    while (true) {
      cur = s[i];
      if (f[cur]) {
        if (cur == p) { 
          next_i = next(i);
          if (next_i >= n) break;
          to = s[next_i]; 
          ans += to; 
          f[to]--; 
        }
        f[cur]--; 
        ans += cur; 
        p = cur; 
      } else {
        i = next(i);
        if (i >= n) break;
      }
    }

    if (ans.size() == n) cout << ans << endl;
    else cout << "IMPOSSIBLE" << endl;
  }

  return 0;
}

