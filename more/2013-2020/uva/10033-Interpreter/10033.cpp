#include <bits/stdc++.h>

using namespace std;

#define MAXN 1005

int RAM[MAXN], R[10];
int t, cmd, idx, ans;
string line;

void run(int cmd) {
  int id = cmd / 100;
  int d = (cmd % 100) / 10;
  int n = cmd % 10;

  switch (id) {
    case 0:
      if (R[n] != 0) 
        idx = R[d] - 1;
      break;
    case 2:
      R[d] = n;
      break;
    case 3:
      R[d] = (R[d] + n) % 1000;
      break;
    case 4:
      R[d] = (R[d] * n) % 1000;
      break;
    case 5:
      R[d] = R[n];
      break;
    case 6:
      R[d] = (R[d] + R[n]) % 1000;
      break;
    case 7:
      R[d] = (R[d] * R[n]) % 1000;
      break;
    case 8:
      R[d] = RAM[R[n]];
      break;
    case 9:
      RAM[R[n]] = R[d];
      break;
    default:
      break;
  }
}

int main() {
  scanf("%d", &t);
  getline(cin, line); // enline of testcases line
  getline(cin, line); // first blank line

  for (int i = 0; i < t; ++i) {
    idx = 0; memset(R, 0, sizeof(R));

    if (i != 0) 
      printf("\n");

    while (getline(cin, line)) {
      if (line == "") break;
      RAM[idx++] = atoi(line.c_str());
    }
    
    idx = ans = 0;
    while (RAM[idx] != 100) {
      ans++;
      run(RAM[idx]); 
      idx++;
    }
    printf("%d\n", ans + 1);
  }
  return 0;
}
