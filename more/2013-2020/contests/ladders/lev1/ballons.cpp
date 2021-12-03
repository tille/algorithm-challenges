#include <bits/stdc++.h>

using namespace std;

int t, n, x, y, num, ini, fin;
string ans;

int main() {
  cin >> t;
  while (t--) {
    cin >> n >> x >> y;
    for (int i = 0; i < n; ++i) {
      cin >> num;
      if (i == 0) ini = num;
      if (i == n-1) fin = num;
    }
    if (ini == x && fin == y) ans = "BOTH";
    else if (ini == x) ans = "EASY";
    else if (fin == y) ans = "HARD";
    else ans = "OKAY";
    
    cout << ans << endl;
  }
  return 0;
}
