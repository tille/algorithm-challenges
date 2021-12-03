#include <bits/stdc++.h>

using namespace std;

#define MAXN 9

char maze[MAXN][MAXN];

int max_black() {
  int res = 1<<30;
  int i;

  for (int j = 1; j <= 8; ++j) {
    int i = 8;
    int dist = 0;
    while (maze[i][j] == '.' && i > -1) {
      dist++;
      i--;
    }
    if (i != -1 && maze[i][j] == 'B' && dist) 
      res = min(res, dist);
  }

  return res;
}

int max_white() {
  int res = 1<<30;
  int i;

  for (int j = 1; j <= 8; ++j) {
    int i = 1;
    int dist = 0;
    while (maze[i][j] == '.' && i < 9) {
      dist++;
      i++;
    }
    if (i != 9 && maze[i][j] == 'W' && dist) 
      res = min(res, dist);
  }

  return res;
}

int main() {
  char c;
  
  for (int i = 1; i <= 8; ++i) {
    for (int j = 1; j <= 8; ++j) {
      cin >> maze[i][j];
    }
  }

  int max_w = max_white();
  int max_b = max_black();

  char ans = (max_w <= max_b) ? 'A' : 'B';
  cout << ans << endl;
    
  return 0;
}
