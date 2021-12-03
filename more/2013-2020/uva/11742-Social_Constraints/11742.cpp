#include <bits/stdc++.h>

using namespace std;

int find(int n, int arr[]) {
  for (int i = 0; i < 8; ++i)
    if (n == arr[i]) return i; 
}

int main() {
  int n, m, ans, a, b, c;
  vector<int> arr;

  while (cin >> n >> m && n+m) {
    arr.clear(); ans = 0;
    int p[8] = {0, 1, 2, 3, 4, 5, 6, 7};

    for (int i = 0; i < m; ++i) {
      cin >> a >> b >> c;
      arr.push_back(a); arr.push_back(b); arr.push_back(c);
    }

    do {
      bool valid = true;
      for (int i = 0; i < m; ++i) {
        int a = find(arr[3 * i], p);
        int b = find(arr[(3 * i) + 1], p);
        int c = arr[(3 * i) + 2];

        // ask queries and inc ans
        bool res = (c < 0) ? abs(a-b) >= abs(c) : abs(a-b) <= c;
        if (!res) valid = false;
      }
      if (valid) ans++;
    } while (next_permutation(p, p + n));

    cout << ans << endl;
  }
  return 0;
}
