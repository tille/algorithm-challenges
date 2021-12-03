#include <bits/stdc++.h>

using namespace std;

int main() {

  long long n, num, tot = 0;

  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> num;
    if (num != 1) tot = tot + (num - 1);

    if (tot % 2) cout << 1 << endl;
    else cout << 2 << endl;
  }

  return 0;
}

