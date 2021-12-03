#include <bits/stdc++.h>

using namespace std;

#define MAXN 105

char ascii[MAXN][MAXN];

bool is_slash(char c) {
  return (c == '/' || c == '\\');
}

int main() {
  int h , w;

  while (cin >> h >> w) {
    int area = 0;

    for (int i = 0; i < h; ++i) {
      bool inside = false;
      for (int j = 0; j < w; ++j) {
        cin >> ascii[i][j];

        if (is_slash(ascii[i][j]) && inside) area++;
        else if (ascii[i][j] == '.' && inside) area++;

        if (is_slash(ascii[i][j])) inside = !inside;
      }
    }
    cout << area << endl;
  }
  return 0;
}
