#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii; 

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define TRmsi(c, it) for (msi::iterator it = (c).begin(); it != (c).end(); it++)

string ans, s_cpy;
map<char, int> ft, f;
int n;
string s, res;
int t, repeated;

int next(int u) {
  int fwd = u + 1;
  return (fwd < n && f[s[fwd]] <= 0) ? next(fwd) : fwd;
}

bool run() {
  ans = "";
  int l = 0, p = s[0]; 
  ans += p, f[p]--; 

  while (true) {
    if (f[s[l]]) {
      if (s[l] == ans[ans.size() - 1]) {
        if (next(l) >= n) break;
        ans += s[next(l)];
        f[s[next(l)]]--;
      }
      ans += s[l];
      f[s[l]]--;
    } else {
      if (next(l) >= n) break;
      l = next(l);
    }
  }

  return f[ans[ans.size() - 1]] <= 0;
}

void fill_freq() {
  repeated = 0;
  REP(i, 0, s.size() - 1) {
    f[s[i]]++;
    ft[s[i]]++;
    repeated = max(repeated, f[s[i]]);
  }
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  while (cin >> s) {
    sort(s.begin(), s.end());
    s_cpy = s;

    ft.clear(), f.clear();
    fill_freq();

    if (repeated > (s.size() - repeated + 1)) {
      cout << "IMPOSSIBLE" << endl; 
      continue;
    }

    // unique s
    res = s[0];
    REP(i, 1, s.size() - 1) 
      if (res[res.size() - 1] != s[i]) 
        res += s[i];

    s = res;
    n = s.size();
    
    if (run()) {
      cout << ans << endl;
    } else {
      char lst = ans[ans.size() - 1];
      int r = (((ft[lst] - f[lst]) * 2) - 1) + f[lst];
      res = s.substr(0, ans.size() - r);
      REP(it, 1, r) f[ans[ans.size() - it]]++;

      s.erase(s.find(lst));
      s = lst + s; 

      run(); 
      res += ans;

      cout << res << endl;
    }
  }
  return 0;
}
