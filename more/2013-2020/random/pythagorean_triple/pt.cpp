#include <bits/stdc++.h>

using namespace std;

int main() {
  int a, b, x, h, h_int, c, c_int, y;
  bool valid;
  set<int> visited;

  while (cin >> a >> b) {
    visited.clear();
    for (int i = a; i <= b - 1; i++) {
      x = i; 
      y = i + 1;
      h = x*x + y*y;
      h_int = sqrt(h);

      if (h_int * h_int == h && visited.count(x +y + h_int) == 0) {
        printf("%d %d %d\n", x, y, h_int);
        visited.insert(x + y + h_int);
      } else {
        c = abs(y*y - x*x);
        h = max(y, x);
        c_int = sqrt(c);

        if (c_int * c_int == c && visited.count(c_int + min(y, x) + h) == 0) { 
          printf("%d %d %d\n", c_int, min(y, x), h);
          visited.insert(c_int + min(x, y) + h);
        }
      }
    }
  }
  return 0;
}
