#include <bits/stdc++.h>

using namespace std;

int s_len, n;
char s[10];

char arr[10][7] = {
/*       0    1    2    3    4    5    6  */
/* 0 */ '-', '|', '|', ' ', '|', '|', '-',
/* 1 */ ' ', ' ', '|', ' ', ' ', '|', ' ',
/* 2 */ '-', ' ', '|', '-', '|', ' ', '-',
/* 3 */ '-', ' ', '|', '-', ' ', '|', '-',
/* 4 */ ' ', '|', '|', '-', ' ', '|', ' ',
/* 5 */ '-', '|', ' ', '-', ' ', '|', '-',
/* 6 */ '-', '|', ' ', '-', '|', '|', '-',
/* 7 */ '-', ' ', '|', ' ', ' ', '|', ' ',
/* 8 */ '-', '|', '|', '-', '|', '|', '-',
/* 9 */ '-', '|', '|', '-', ' ', '|', '-'
};

void print_one_segment(int seg) {
  for (int i = 0; i < s_len; i++) {
    int num = s[i] - '0';
    if (i) printf(" ");

    printf(" ");
    for (int j = 0; j < n; ++j) printf("%c", arr[num][seg]); 
    printf(" ");
  }
  printf("\n");
}

void print_two_segments(int seg_1, int seg_2) {
  for (int row = 1; row <= n; ++row) {
    for (int i = 0; i < s_len; i++) {
      int num = s[i] - '0';
      if (i) printf(" ");

      printf("%c", arr[num][seg_1]);
      for (int j = 0; j < n; ++j) printf(" ");
      printf("%c", arr[num][seg_2]);
    }
    printf("\n");
  }
}

int main() {
  while (scanf("%d %[0-9]", &n, &s) != EOF) {
    if (s[0] - '0' + n == 0) break;

    s_len = strlen(s);

    print_one_segment(0);
    print_two_segments(1, 2);
    print_one_segment(3);
    print_two_segments(4, 5);
    print_one_segment(6);

    printf("\n");
  }
  return 0;
}

