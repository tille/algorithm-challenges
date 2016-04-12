#include <bits/stdc++.h>
using namespace std;
#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)

bool blank(string &s) {
  REP(i, 0, s.size() - 1) if (s[i] != ' ') return false;
  return true;
}

void trim(string s) {
  cout << s << endl;
}

int main() {
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL);
  string line, all = "";

  while (getline(cin, line)) all += line + '\n';
   
  int ini = 0, space = -1;
  REP(i, 0, all.size() - 1) {
    if (all[i] == '\n') {
      line = all.substr(ini, i - ini);
      if ((blank(line) or i - ini <= 1) or (all[i + 1] == ' ' or all[i + 1] == '\n')) {
        if (i - ini > 72) {
          if (space == ini) cout << line << endl;
          else {
            cout << all.substr(ini, space - ini) << endl;
            ini = space + 1;
            cout << all.substr(ini, i - ini) << endl;
          }
        } else cout << line << endl;

        ini = i + 1;
      } else {
        all[i] = ' ';
      }
    }

    if (all[i] == ' ') {
      if (i - ini > 72 && space == -1) {
        cout << all.substr(ini, i) << endl;
        ini = i + 1;
      } else if (i - ini > 72) {
        cout << all.substr(ini, space - ini) << endl;
        ini = space + 1;

        if (i == all.size() - 1) {
          cout << all.substr(ini, i - ini) << endl;
        }
      } else if (i == all.size() - 1) {
        cout << all.substr(ini, i - ini) << endl;
      }
      space = i;
    }
  }
  return 0;
}

