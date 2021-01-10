#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);

  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  long ans = LONG_MIN;

  for (int j = 0; j < n; ++j) {
    for (int i = 0; i <= j; ++i) {

      long sum = 0;
      for (int k = i; k <= j; ++k) {
        sum += a[k];
      }
      ans = max(ans, sum);

    }
  }

  cout << ans << endl;
  return 0;
}