#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) \
  for (int i = int(a); i <= int(b); i++)

int m[6], w[6], hs, hu;
int x[5] = {500, 1000, 1500, 2000, 2500};

int main() {
  REP(i, 0, 4)
    scanf("%d", &m[i]);
  REP(i, 0, 4)
    scanf("%d", &w[i]);
  scanf("%d %d", &hs, &hu);

  double ans = 0;
  REP(i, 0, 4) {
    int left = 0.3 * x[i];
    int right = (x[i] - (m[i] * x[i])/250);
    ans += max(left, right - w[i] * 50);
  }
  ans += (hs * 100);
  ans -= (hu * 50);

  printf("%d\n", int(ans));

  return 0;
}

