#include <bits/stdc++.h>

using namespace std;

int main() {
  int num;
  set<int> s;

  while (cin >> num) {
    int rest = 2020 - num;

    if (s.count(rest)) {
      cout << rest*num << endl;
      break;
    } else {
      s.insert(num);
    }
  }
  return 0;
}