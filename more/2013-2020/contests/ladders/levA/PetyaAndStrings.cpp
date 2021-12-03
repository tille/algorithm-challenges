#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii; 

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define TRmsi(c, it) for (msi::iterator it = (c).begin(); it != (c).end(); it++)

string a, b;
int ans;

int main() {
  cin >> a >> b; 
  ans = 0;
  REP(i, 0, a.size() - 1) {
    if (tolower(a[i]) < tolower(b[i])) {
      ans = -1; break;
    } else if (tolower(a[i]) > tolower(b[i])) {
      ans = 1; break;
    }
  }
  cout << ans << "\n";
  return 0;
}

