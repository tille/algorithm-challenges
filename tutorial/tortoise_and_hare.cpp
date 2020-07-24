#include <bits/stdc++.h>

using namespace std;
#define MAXN 100

int main() {
  int n;
  int nums[MAXN];

  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> nums[i];
  }

  int t = nums[0];
  int h = nums[0];
  int q = -1;

  while (true) {
    t = nums[t];
    h = nums[nums[h]];
    if (t == h) {
      q = t;
      break;
    }
  }

  int p = nums[0];
  while(p != q) {
    p = nums[p];
    q = nums[q];
  }

  cout << p << endl;

  return 0;
}