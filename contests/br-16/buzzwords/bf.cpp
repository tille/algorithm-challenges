#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii; 

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define TRmsi(c, it) for (map<char, int>::iterator it = (c).begin(); it != (c).end(); it++)

int main() {
  map<char, int> h;
  string s;
  getline(cin, s);
  for (int i = 0; i < s.size(); ++i) {
    if (h[s[i]]) continue;
    for (int j = 0; j < s.size(); ++j) {
      if (s[i] == s[j]) {
        h[s[i]]++;
      }
    }
  }

  TRmsi(h, it) {
    cout << it->first << " " << it->second << endl;
  }
  return 0;
}

