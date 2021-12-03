#include <bits/stdc++.h>

using namespace std;

int main() {
  int t, A, B, C; cin >> t;
  
  while (t--) {
    cin >> A >> B >> C;

    bool sol = false; int x, y, z;

    for (int x = -100; x <= 100 && !sol; ++x) {
      for (int y = -100; y <= 100 && !sol; ++y) {
        for (int z = -100; z <= 100 && !sol; ++z) {
          if (y != x && y != z && x != z &&
              x + y + z == A && x * y * z == B &&
              x * x + y * y + z * z == C) {
            printf("%d %d %d\n", x, y, z);
            sol = true;
          }
        }
      }
    }

    if (!sol) 
      printf("No solution.\n");
  }
  return 0;
}
