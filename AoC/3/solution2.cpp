#include <bits/stdc++.h>

using namespace std;

int main() {
  vector<string> map;
  int cont = 0;
  int cont2 = 0;
  int cont3 = 0;
  int cont4 = 0;
  int cont5 = 0;

  int tree1 = 0, tree2 = 0, tree3 = 0, tree4 = 0, tree5 = 0;
  string s;
  int t = 0;

  while(cin >> s) {
    if (t % 2 == 0) {
      if (s[cont5 % s.size()] == '#') tree5++;
      cont5 += 1;
    }

    if (s[cont % s.size()] == '#') tree1++;
    if (s[cont2 % s.size()] == '#') tree2++;
    if (s[cont3 % s.size()] == '#') tree3++;
    if (s[cont4 % s.size()] == '#') tree4++;

    cont += 1;
    cont2 += 3;
    cont3 += 5;
    cont4 += 7;
    t++;
  }
  cout << tree1 << endl;
  cout << tree2 << endl;
  cout << tree3 << endl;
  cout << tree4 << endl;
  cout << tree5<< endl;

  long long ans = ((long long)tree1 * tree2 * tree3 * tree4 * tree5);
  cout << ans << endl;
  return 0;
}