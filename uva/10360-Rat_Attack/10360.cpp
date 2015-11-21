#include <bits/stdc++.h>

using namespace std;

#define MAXN 1027

int killed[MAXN][MAXN];

int main() {
  int TC, d, n, x, y, rats, ans_r, ans_c, best; 
  scanf("%d", &TC);

  while (TC--) {
    cin >> d >> n;

    for (int i = 0; i < MAXN; ++i) 
      for (int j = 0; j < MAXN; ++j) 
        killed[i][j] = 0;
    best = -1;

    for (int ratCell = 0; ratCell < n; ++ratCell) {
      scanf("%d %d %d", &x, &y, &rats);
      for (int c = x-d; c <= x+d; ++c)
        for (int r = y-d; r <= y+d; ++r)
          if (r >= 0 && r < 1024 && c >= 0 && c < 1024)
            killed[c][r] += rats;
    }

    for (x = 0; x < 1024; x++)
      for (int y = 0; y < 1024; y++)
        if (killed[x][y] > best) {
          ans_r = x; ans_c = y; best = killed[x][y]; }

    printf("%d %d %d\n", ans_r, ans_c, best);
  }
  return 0;
}

