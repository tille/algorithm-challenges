#include <bits/stdc++.h>

using namespace std;

#define MAXN 505

int locations[MAXN];

int main() {
  int t, n, total, i, num, x;
  scanf("%d", &t);

  while (t--) {
    scanf("%d", &n);

    for (i = 0; i < n; ++i)
      scanf("%d", &locations[i]);

    sort(locations, locations + n);
    x = locations[int(n / 2)];

    total = 0;
    for (int i = 0; i < n; ++i)
      total += abs(locations[i] - x);

    printf("%d\n", total);
  }
  return 0;
}

