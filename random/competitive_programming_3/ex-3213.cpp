#include <bits/stdc++.h>

using namespace std;

#define MAXN 4

bitset<30> rw;
int row[MAXN];

void next_permutation(int c) {
  if (c == 3) {
    for (int j = 0; j < 3; ++j) 
      printf("%d ", row[j] + 1);
    printf("\n");
  }
  for (int r = 0; r < 3; ++r) {
    if (!rw[r]) {
      rw[r] = true;
      row[c] = r; next_permutation(c + 1);
      rw[r] = false;
    }
  }
}

int main() {
  int p[3] = {1, 2, 3};

  // do {
  //   printf("%d %d %d\n", p[0], p[1], p[2]);
  // } while (next_permutation(p, p+3));

  next_permutation(0);

  return 0;
}

// since java does not have a built-in next_permutation function
// we can define our own recursive backtracking routine 
// to generate all permutations!
