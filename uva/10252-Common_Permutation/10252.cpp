#include <bits/stdc++.h>
using namespace std;
#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)

string s[2];

int main() {
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL);
  string s[2];

  while (getline(cin, s[0]) && getline(cin, s[1])) {
    map<char, int> vis;
    string ans = "";
    if (s[1].size() > s[0].size()) swap(s[0], s[1]);

    sort(s[1].begin(), s[1].end());
    sort(s[0].begin(), s[0].end());

    REP(i, 0, s[0].size() - 1)
      vis[s[0][i]]++;

    REP(j, 0, s[1].size() - 1) {
      char cur = s[1][j];
      if (vis[cur]) {
        ans += cur;
        vis[cur] -= 1;
      }
    }
    cout << ans << endl;
  }
   
  return 0;
}
