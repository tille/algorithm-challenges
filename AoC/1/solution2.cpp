#include <bits/stdc++.h>

using namespace std;

int main() {
  int num;
  set<int> s;
  vector<int> v;
  
  while (cin >> num) {
    v.push_back(num);
  }

  for (int i = 0; i < v.size(); ++i) {
    for (int j = 0; j < v.size(); ++j) {
      for (int k = 0; k < v.size(); ++k) {
        if (v[i] + v[j] + v[k] == 2020) {
          cout << v[i] * v[j] * v[k] << endl;
          return 0;
        }
      }
    }
  }

  return 0;
}