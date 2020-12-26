#include <bits/stdc++.h>

using namespace std;

int main() {
  string s; int ans = 0;
  vector<int> v;

  while(cin >> s) {
    int i = 0, j = 127, cont = 0;
    
    while (i != j) {
      if (s[cont] == 'F') {
        j = (i + j) / 2;
      } else {
        i = ceil((i + j) / 2.0);
      }
      cont++;
    }

    int row = i;
    i = 0, j = 7;

    while (i != j) {
      if (s[cont] == 'L') {
        j = (i + j) / 2;
      } else {
        i = ceil((i + j) / 2.0);
      }
      cont++;
    }

    int col = i;
    int temp = row * 8 + col;

    // if (temp > ans) {
      // ans = temp;
    // }
    v.push_back(temp - 8);
  }

  int ini = 0;
  for (int i = 0; i < v.size(); ++i) {
    ini = ini ^ (v[i] ^ i);
    // if (v[i] == 381) cout << "esta" << endl;
  }
  cout << ini << endl;

  // sort(v.begin(), v.end());
  // for (int i = 0, j = 8; i < v.size(); ++i, j++) {
  //   cout << v[i] << endl;
  // }
  
  return 0;
}