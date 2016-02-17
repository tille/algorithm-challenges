#include <bits/stdc++.h>

using namespace std;

int h1, h2;
int t1, t2;
double x, ans;

int main() {
  cin >> h1 >> t1;
  cin >> h2 >> t2;
  x = sqrt(h1 / double(h2));
  ans = (x * t2) - t1 / x - 1;
  cout << ans << endl;
  return 0;
}

