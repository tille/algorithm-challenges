#include <bits/stdc++.h>

using namespace std;

int count_diff(int a, int b) {
  set<int> s;
  if (b < 10000) s.insert(0);
  while (a) { s.insert(a%10); a /= 10; }
  while (b) { s.insert(b%10); b /= 10; }
  return s.size();
}

int main() {
  int n, testcase = 0;

  while (cin >> n && n) {
    bool found = false; testcase++;
    if (testcase != 1) printf("\n");

    for (int b = 1234; b <= 98765 / n; ++b) {
      int a = b * n;
      int cont = count_diff(a, b);
      if (cont == 10) { printf("%0.5d / %0.5d = %d\n", a, b, n); found = true; }
    }

    if (!found)
      printf("There are no solutions for %d.\n", n);
  }
  return 0;
}
