#include <bits/stdc++.h>

using namespace std;

int main() {
  vector<string> map;
  int cont = -3, tree = 0;
  string s;

  while(cin >> s) {
    cont += 3;
    if (s[cont % s.size()] == '#') tree++;
  }
  cout << tree << endl;
  return 0;
}