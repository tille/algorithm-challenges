#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) \
  for (int i = int(a); i <= int(b); i++) 
#define MAXN 260

int dy[4] = {-1,  0, 0, 1};
int dx[4] = { 0, -1, 1, 0};

int n, m, col, row;
int col1, col2, row1, row2;
char color;
char picture[MAXN][MAXN];
char s[1000];

bool valid_index(int row, int col) {
  return (row >= 1 && row <= n && col >= 1 && col <= m);
}

void bfs(int row, int col) {
  char old_color = picture[row][col];
  picture[row][col] = color;

  REP(k, 0, 3) {
    int i = row + dy[k]; int j = col + dx[k];
    if (picture[i][j] == old_color && valid_index(i, j))
      bfs(i, j);
  }
}

void print_image() {
  for (int r = 1; r <= n; ++r) {
    for (int c = 1; c <= m; ++c)
      printf("%c", picture[r][c]);
    printf("\n");
  }
}

void fill_rect(int x1, int y1, int x2, int y2, char color) {
  if (x1 > x2) swap(x1, x2);
  if (y1 > y2) swap(y1, y2);

  REP(r, y1, y2) 
    REP(c, x1, x2) 
      if ( valid_index(r, c) )
        picture[r][c] = color;
}

void run(char id) {
  switch (id) {
    case 'I':
      scanf("%d %d", &m, &n);
      fill_rect(1, 1, m, n, 'O');
      break;
    case 'C':
      fill_rect(1, 1, m, n, 'O');
      break;
    case 'L':
      scanf("%d %d %c", &col, &row, &color);
      picture[row][col] = color;
      break;
    case 'V':
      scanf("%d %d %d %c", &col, &row1, &row2, &color); 
      fill_rect(col, row1, col, row2, color);
      break;
    case 'H':
      scanf("%d %d %d %c", &col1, &col2, &row, &color);
      fill_rect(col1, row, col2, row, color);
      break;
    case 'K':
      scanf("%d %d %d %d %c", &col1, &row1, &col2, &row2, &color);
      fill_rect(col1, row1, col2, row2, color);
      break;
    case 'F':
      scanf("%d %d %c", &col, &row, &color); 
      if (picture[col][row] != color) bfs(row, col);
      break;
    case 'S':
      scanf("%s", &s); printf("%s\n", s);
      print_image();
      break;
    default: 
      break;
  }
}

int main() {
  char id;
  while (scanf("%c", &id) != EOF) {
    if (id == 'X') break;
    run(id);
  }
  return 0;
}
