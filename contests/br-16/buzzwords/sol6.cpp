#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef map<int, int> msi;

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define P 997
#define M 1000002

string line, s;
int ini, max_elm, f, n;

int main() {
  while (1) {
    getline(cin, line);
    if (line == "0") break;
    
    s = ""; 
    REP(i, 0, line.size() - 1) {
      if (line[i] != ' ') 
        s += line[i];
    }

    n = s.size();
    // msi H[n + 1];
    vector<msi > H(n + 1);

    REP(i, 0, n - 1) {
      f = s[i]; 
      H[1][f]++;
      REP(j, i + 1, n - 1) {
        f = (((f * P) % M) + int(s[j])) % M;
        H[j - i + 1][f]++;
      }
    }

    REP(i, 1, n) {
      msi V = H[i];
      max_elm = -1;

      for (msi::iterator it = V.begin(); it != V.end(); ++it)
        max_elm = max(max_elm, it->second);

      cout << max_elm << endl;
      if (max_elm == 1) break;
    }
  }
  return 0;
}
