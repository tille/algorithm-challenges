#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii; 

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define push_back pb

int main() {
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL);
  string line;
   
  while (getline(cin, line)) {
    string ans = "";
    bool valid = true;

    REP(i, 0, line.size() - 1) {
      if (line[i] == 'o' || line[i] == 'O') ans += "0";
      else if (line[i] == 'l') ans += "1";
      else if ((line[i] - '0') >= 0 && (line[i] - '0' <= 9)) ans += line[i];
      else if (isalpha(line[i])) {
        valid = false;
        break;
      }
    }

    while (ans[0] == '0' && ans.size() > 1) ans.erase(ans.begin() + 0);

    if (valid && ans.size() > 0 && ans.size() <= 10) {
      ll res;
      stringstream ss(ans);
      ss >> res;
      if (res > 2147483647) {
        cout << "error" << endl;
      } else {
        cout << res << endl;
      }
    } else {
      cout << "error" << endl;
    }
  }
  return 0;
}

