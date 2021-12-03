#include <bits/stdc++.h>

using namespace std;

#define MAXN 23
int l[MAXN];

int main() {
  int t; cin >> t;

  while (t--) {
    int x, p; bool found = false;

    cin >> x >> p;

    for (int i = 0; i < p; i++) 
      cin >> l[i];

    for (int i = 0; i < (1 << p); ++i) {
      int sum = 0;
      for (int j = 0; j < p; ++j)
        if (i & (1 << j))
          sum += l[j];
      if (x == sum) { found = true; break; }
    }

    string ans = (found) ? "YES" : "NO";
    cout << ans << endl;
  }
  return 0;
}
