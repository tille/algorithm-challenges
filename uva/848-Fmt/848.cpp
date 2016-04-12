#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii; 

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define TRmsi(c, it) for (msi::iterator it = (c).begin(); it != (c).end(); it++)

bool blank(string s) {
  REP(i, 0, s.size() - 1)
    if (s[i] != ' ') 
      return false;
  return true;
}

int main() {
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL);
  string line, all;
  stringstream ss;

  while (getline(cin, line)) {
    all += line;
    all += '\n';
  }

  int ini = 0, space = 0, line_break = 0;
  for (int i = 0; i < all.size(); ++i) {
    // if (i == all.size()) {
    //   if (i - ini > 72) all[space] = '\n';
    //   all += '\n';
    //   break;
    // }

    if (all[i] == '\n') {
      line = all.substr(ini + 1, i - ini - 1);
      if (!blank(line) && (all[i + 1] != all[i] && all[i] != all[i - 1] && all[i + 1] != ' ')) {
        all[i] = ' ';
      } else {
        ini = i + 1;
      }
    }

    if (all[i] == ' ') {
      // cout << all.substr(space, i - space);
      // cout << ini << " " << i << " " << i - ini << endl;
      if (i - ini > 72 && !space) space = i;
      if (i - ini > 72 && space) {
        all[space] = '\n';
        ini = space + 1;
      }
      space = i;
    }
  }

  cout << all << endl;

  return 0;
}
