#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii; 

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define TRmsi(c, it) for (msi::iterator it = (c).begin(); it != (c).end(); it++)

int n, t;

string next_state(string &str) {
  REP(i, 0, str.size() - 2) {
    if (str[i] == 'B' && str[i + 1] == 'G') {
      swap(str[i], str[i + 1]);
      i++;
    }
  }
  return str;
}

int main() {
  string s;
  cin >> n >> t >> s;
  while (t--) {
    s = next_state(s);
  }
  cout << s << "\n";
  return 0;
}

