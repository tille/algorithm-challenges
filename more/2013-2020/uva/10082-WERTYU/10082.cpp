#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii; 

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define TRmsi(c, it) for (msi::iterator it = (c).begin(); it != (c).end(); it++)

string alpha = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";
map<char, char> memo;

int main() {
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL);
  string line;

  memo[' '] = ' ';
  REP(i, 1, alpha.size() - 1) {
    memo[alpha[i]] = alpha[i - 1];
  }

  while (getline(cin, line)) {
    REP(i, 0, line.size() - 1) {
      cout << memo[line[i]];
    }
    cout << endl;
  }

  return 0;
}
