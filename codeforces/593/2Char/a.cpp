#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  int ans = 0;
  string s;
  vector<string> words;

  for (int i = 0; i < n; ++i) {
    cin >> s;
    set<int> visited;
    bool valid = true;
    
    for (int j = 0; j < s.size(); ++j) {
      int c = s[j];
      if (!visited.count(c)) visited.insert(c);
      if (visited.size() > 2) {
        valid = false;
        break;
      }
    }
    if (valid) words.push_back(s);
  }

  for (char i = 'a'; i <= 'z'; ++i) {
    for (char j = 'a'; j <= 'z'; ++j) {

      int res = 0;
      for (int k = 0; k < words.size(); ++k) {

        int valid = true;
        for (int u = 0; u < words[k].size(); ++u) {
          if (words[k][u] != i && words[k][u] != j) {
            valid = false;
            break;
          }
        }

        if (valid) res += words[k].size();
      }
      ans = max(ans, res);
    }
  }

  cout << ans << endl;
  return 0;
}
