#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii; 

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define TRmsi(c, it) for (msi::iterator it = (c).begin(); it != (c).end(); it++)

int t;
string str;

int main() {
  cin >> t;
  while (t--) {
    cin >> str;
    if (str.size() > 10) {
      stringstream ss; ss << str.size() - 2;
      str = str[0] + ss.str() + str[str.size() - 1];
    }
    cout << str << "\n";
  }
  return 0;
}

