#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii; 

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define TRmsi(c, it) for (msi::iterator it = (c).begin(); it != (c).end(); it++)

const int M = 1e5;
const int P = 997;

map<int, int> h;
string s;
int str_hash, f_str, ans, char_before, n;

int c_pot(int x, int n) {
  int res = 1;
  while (n--) res = (res * x) % M;
  return res;
}

int hashing(string str) {
  f_str = 0;
  int fwd = 0;
  for (int i = str.size() - 1; i >= 0; i--) {
    int char_val = (int(str[i]) * c_pot(P, fwd)) % M;
    f_str = (f_str + char_val) % M;
    fwd++;
  }
  return f_str;
}

int main() {
  cout.sync_with_stdio(false);
  while (getline(cin, s) && s != "0") {
    string s_cpy = "";
    REP(j, 0, s.size() - 1) if (s[j] != ' ') s_cpy += s[j];
    s = s_cpy;
    n = s.size();

    REP(k, 1, n) {
      ans = 0, h.clear();
      REP(i, 0, n - k) {
        if (!i)
          str_hash = hashing(s.substr(0, k));
        else {
          // all this block can be oneline but is nice to have readadability
          char_before = (int(s[i - 1]) * c_pot(P, k - 1)) % M;
          str_hash = (str_hash - char_before + M) % M;
          str_hash = (str_hash * P) % M;
          str_hash = (str_hash + int(s[i + k - 1])) % M;
        }
        h[str_hash]++;
        ans = max(ans, h[str_hash]);
      }
      cout << ans << endl;
      if (ans == 1) break;
    }
  }
  return 0;
}

