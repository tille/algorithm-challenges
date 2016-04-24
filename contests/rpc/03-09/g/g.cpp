#include <bits/stdc++.h>
using namespace std;
long double xl, yl, xr, yr, ans;

int main() {
  cout << fixed << setprecision(7);

  while (cin >> xl >> yl >> xr >> yr) {
    xr = abs(xr - xl), yr = abs(yr - yl);
    ans = ((xr * xr) / 6.0) + ((yr * yr) / 6.0);
    cout << ans << endl;
  }
  return 0;
}

