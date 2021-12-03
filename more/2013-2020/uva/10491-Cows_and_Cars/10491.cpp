#include <bits/stdc++.h>
using namespace std;

int cows, cars, shown;

int main() {
  while (scanf("%d %d %d", &cows, &cars, &shown) != EOF) {
    int n = cows + cars;
    double pcows = cows / double(n);
    double pcars = cars / double(n);

    int n2 = (cows - shown) + cars;
    double p1 = cars / double(n2 - 1);
    double p2 = (cars - 1) / double(n2 - 1);

    double ans = (pcars * p2) + (pcows * p1);
    printf("%.5f\n", ans);
  }
  return 0;
}

