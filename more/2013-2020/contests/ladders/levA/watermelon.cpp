#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii; 

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define TRmsi(c, it) for (msi::iterator it = (c).begin(); it != (c).end(); it++)

int main() {
  int n;
  cin >> n;
  string ans = (n % 2 == 0 && n != 2) ? "YES" : "NO";
  cout << ans << "\n";
  return 0;
}

