#include <bits/stdc++.h>

int main() {
  int t, n, m;
  scanf("%d", &t);
  while (t--) {
    scanf("%d %d", &n, &m); n-=2; m-=2;
    printf("%d\n", int(ceil(n/3.0) * ceil(m/3.0)));
  }
  return 0;
}

