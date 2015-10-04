#include <bits/stdc++.h>

using namespace std;

#define MAXN 52

int main() {
  int n, k, i, j, ans;
  int scores[MAXN];

  while (cin >> n >> k) {
    i = 0;

    while (i < n) {
      cin >> scores[i];
      i++;
    }

    j = 0;
    ans = 0;

    while (j < n) {
      if (scores[j] > 0 && scores[j] >= scores[k-1]) ans++;
      j++;
    }

    cout << ans << endl;
  }

  return 0;
}
