#include <bits/stdc++.h>

using namespace std;

#define MAXN 105

int res[MAXN][MAXN];
char mines[MAXN][MAXN];

void place_mine(int a, int y) {
  for (int i = a-1; i <= a+1; ++i) {
    for (int j = y-1; j <= y+1; ++j) {
      if (i == a && j == y) continue;
      res[i][j]++;
    }
  }
}

void print_ans(int n, int m, int t) {
  cout << "Field #" << t << ":" << endl;

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (mines[i][j] != '*') cout << res[i][j];
      else cout << "*";
    }
    puts("");
  }
}

void clear() {
  for (int i = 0; i < MAXN; ++i) {
    memset(res[i], 0, sizeof res[i]);
  }
}

int main() {
  int n, m; int testcase = 1;
  char c;

  while (cin >> n >> m && n+m) {
    if (testcase != 1) puts("");
    clear();

    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) {
        cin >> mines[i][j];
        if (mines[i][j] == '*') place_mine(i, j);
      }
    }

    print_ans(n, m, testcase);
    testcase++;
  }
  return 0;
}
