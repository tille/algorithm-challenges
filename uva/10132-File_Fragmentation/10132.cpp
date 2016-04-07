#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi; 

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)

int t, tot;
vector<string> fra;
string line;

bool sorting(string a, string b) {
  return a.size() < b.size();
}

bool matching(vector<bool> &vis, int cnt, string cur, int c) {
  if (cnt == fra.size()) 
    return true;

  REP(j, 0, fra.size() - 1) {
    if (!vis[j] && (fra[c] + fra[j] == cur || fra[j] + fra[c] == cur)) {
      vis[c] = vis[j] = true;
      if (matching(vis, cnt + 2, cur, c - 1)) return true; 
      vis[c] = vis[j] = false;
    }
  }
  return false;
}

int main() {
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL);
  cin >> t;
  getline(cin, line); // endline
  getline(cin, line); // blankline

  while (t--) {
    fra.clear(); 

    while(getline(cin, line) && line.size()) 
      fra.push_back(line);

    sort(fra.begin(), fra.end(), sorting);
    int n = fra.size();
    vector<bool> vis(n, false);
    tot = fra[n - 1].size() + fra[0].size();

    string ans = "";
    for (int i = 0; fra[i].size() == (tot - fra[n - 1].size()); ++i) {
      vis[i] = vis[n - 1] = true;

      if (matching(vis, 2, fra[i] + fra[n - 1], n - 2)) ans = fra[i] + fra[n - 1];
      else if (matching(vis, 2, fra[n - 1] + fra[i], n - 2)) ans = fra[n - 1] + fra[i];

      vis[i] = vis[n - 1] = false;
      if (ans.size()) break;
    } 

    cout << ans << endl;
    if (t) cout << endl;
  }
  return 0;
}

