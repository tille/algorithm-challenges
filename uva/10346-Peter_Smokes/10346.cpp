#include <bits/stdc++.h>

using namespace std;

int main() {
  long long n, k, res, butts;

  while (cin >> n >> k) {
    res = n;
    butts = 0;

    while (n) {
      butts += n%k;
      n = n/k + butts/k;
      butts = butts%k;
      res += n;
    }
    cout << res << endl;
  }

  return 0;
}
