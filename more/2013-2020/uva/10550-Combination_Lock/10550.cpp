#include <cstdio>
#include <algorithm>

int turn(int from, int to, bool clockwise) {
  if (!clockwise) std::swap(to, from);
  int res = (from > to) ? from - to : 40 - to + from;
  return res * 9;
}

int main() {
  int ans, ini, c1, c2, c3;
  while (scanf("%d %d %d %d", &ini, &c1, &c2, &c3), ini || c1 || c2 || c3) {
    ans = 1080;
    ans += turn(ini, c1, true);
    ans += turn(c1, c2, false);
    ans += turn(c2, c3, true);
    printf("%d\n", ans);
  }
  return 0;
}

