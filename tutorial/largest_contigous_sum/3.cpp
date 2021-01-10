#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  vector<long> prefix(n);

  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    prefix[i] += a[i];
  }

  long ans = LONG_MIN;

  for (int j = 0; j < n; ++j) {
    for (int i = 0; i <= j; ++i) {
      long sum = i > 0 ? prefix[j] - prefix[i - 1] : prefix[j];
      ans = max(ans, sum);
    }
  }

  cout << ans << endl;
  return 0;
}