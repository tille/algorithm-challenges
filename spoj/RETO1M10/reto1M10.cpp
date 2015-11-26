#include <bits/stdc++.h>

using namespace std;

int main() {
  int n; vector<bool> seen(100001, false);
  scanf("%d", &n);

  for (int i = 0; i < n; ++i) {
    int episode; scanf("%d", &episode);
    seen[episode - 1] = true;
  }
  vector<bool>::iterator it = find(seen.begin(), seen.begin() + n - 1, false);
  printf("%d\n", it - seen.begin() + 1);

  return 0;
}

