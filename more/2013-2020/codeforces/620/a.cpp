#include <bits/stdc++.h>

using namespace std;

int x11, y11, x22, y22, ans, dx, dy;

int main() {
  cin >> x11 >> y11;
  cin >> x22 >> y22;

  dx = abs(x11 - x22);
  dy = abs(y11 - y22);

  ans = (dx < dy) ? dx + (dy - dx) : dy + (dx - dy);

  cout << ans << endl;
  return 0;
}
