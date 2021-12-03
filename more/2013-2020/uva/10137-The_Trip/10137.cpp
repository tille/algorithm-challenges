#include <bits/stdc++.h>

using namespace std;

int main () {
  int n, x, y;
  double val, avg_ceil, avg_floor, above, bottom, acum;
  vector<double> values;

  while (scanf("%d", &n) && n) {
    values.clear(); acum = 0;

    for (int i = 0; i < n; ++i) {
      scanf("%d.%d", &x, &y);
      val = 100 * x + y;
      values.push_back(val);
      acum += val;
    }

    avg_floor = floor(acum / (double)n);
    avg_ceil = ceil(acum / (double)n);

    above = bottom = 0;
    for (int i = 0; i < n; ++i) {
      if (values[i] < avg_floor) above += avg_floor - values[i];
      else if (values[i] > avg_ceil) bottom += values[i] - avg_ceil;
    }

    printf("$%.2f\n", max(bottom, above)/100.0);
  }
  return 0;
}

// what is better round average value to ceil or floor?
// answer is just the maximum between them
// because at choose maximum value we miss the less amount of money
