#include <bits/stdc++.h>

using namespace std;

int main() {
  set<char> s;
  string line;
  long ans = 0;

  while (getline(cin, line)) {
    if (line == "") {
      ans += s.size();
      s.clear();
    }

    for (auto i : line) 
      s.insert(i);
  }

  ans += s.size();
  cout << ans << endl;

  return 0;
}