#include <bits/stdc++.h>

using namespace std;

#define MAXN 52
long long fib[MAXN];

void calc() {
  fib[0] = fib[1] = 1;
  for (int i = 2; i < MAXN; ++i) {
    fib[i] = fib[i-1] + fib[i-2];
  }
}

int main() {
  int n;

  calc();

  while (cin >> n && n) {
    cout << fib[n] << endl;
  }
  return 0;
}
