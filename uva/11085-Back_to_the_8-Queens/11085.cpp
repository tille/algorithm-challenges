#include <bits/stdc++.h>

using namespace std;

int TC = 0, moves, b[8], row[8];
bitset<20> rw, ld, rd;

void backtrack(int c) {
  if (c == 8) {
    int dist = 0;
    for (int j = 0; j < 8; ++j)
      if (abs(row[j] - b[j]) > 0) dist++;
    moves = min(moves, dist);
    return;
  }
  for (int r = 0; r < 8; ++r) {
    if (!rw[r] && !ld[r - c + 7] && !rd[r + c]) {
      rw[r] = ld[r - c + 7] = rd[r + c] = true;
      row[c] = r; backtrack(c + 1);
      rw[r] = ld[r - c + 7] = rd[r + c] = false;
    }
  }
}

int main() {
  while (scanf("%d %d %d %d %d %d %d %d", &b[0], &b[1], &b[2], &b[3], &b[4], &b[5], &b[6], &b[7]) != EOF) {
    for (int j = 0; j < 8; ++j) b[j]--;
    memset(row, 0, sizeof row); moves = 1<<30;
    backtrack(0); 
    printf("Case %d: %d\n", ++TC, moves);
  }
  return 0;
}

