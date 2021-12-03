#include <bits/stdc++.h>

using namespace std;

bitset<20> rw, ld, rd;
int board[8][8], row[8], best_score;

void backtrack(int c) {
  if (c == 8) {
    int score = 0;
    for (int j = 0; j < 8; ++j) score += board[row[j]][j];
    best_score = max(best_score, score);
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
  int TC; scanf("%d", &TC);

  while (TC--) {
    for (int r = 0; r < 8; ++r) 
      for (int c = 0; c < 8; ++c) 
        scanf("%d", &board[r][c]);

    best_score = 0;
    backtrack(0);
    printf("%5d\n", best_score);
  }
  return 0;
}
