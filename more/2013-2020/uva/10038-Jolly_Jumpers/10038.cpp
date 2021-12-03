#include <bits/stdc++.h>

using namespace std;

#define MAXN 3000
#define REP(i, a, b) \
  for (int i = int(a); i <= int(b); i++)

int n, num, pos, back, k;
string ans;
bitset<MAXN> visited;

int main() {
  while (scanf("%d", &n) != EOF) {
    visited.reset();

    REP(i, 0, n - 1) {
      scanf("%d", &num);
      if (i) {
        pos = abs(num - back) - 1;
        if (pos < (n - 1) && pos >= 0) visited[pos] = true; }
      back = num; }

    bool jolly = false;
    for (k = 0; k < (n - 1) && visited[k]; ++k);
    ans = (k == n - 1) ? "Jolly" : "Not jolly";
    printf("%s\n", ans.c_str());
  }
  return 0;
}

