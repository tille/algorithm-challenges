#include <bits/stdc++.h>

using namespace std;

int row[8], TC, a, b, lineCounter; 
bitset<30> rw, ld, rd;

void backtrack(int c) {
  if (c == 8) {
    printf("%2d      %d", ++lineCounter, row[0] + 1);
    for(int j = 1; j < 8; ++j) printf(" %d", row[j] + 1);
    printf("\n"); 
  }
  for (int r = 0; r < 8; ++r) {
    if (c == b && r != a) continue;
    if (!rw[r] && !ld[r - c + 7] && !rd[r + c]) {
      rw[r] = ld[r - c + 7] = rd[r + c] = true;
      row[c] = r; backtrack(c + 1); 
      rw[r] = ld[r - c + 7] = rd[r + c] = false;
    }
  }
}

int main() {
  scanf("%d", &TC);
  while (TC--) {
    scanf("%d %d", &a, &b); a--; b--;
    memset(row, 0, sizeof row); lineCounter = 0;
    printf("SOLN       COLUMN\n");
    printf(" #      1 2 3 4 5 6 7 8\n\n");
    backtrack(0);
    if (TC) printf("\n");
  }
  return 0;
}
