#include <bits/stdc++.h>

using namespace std;

bool balanced(string str) {
  stack<char> s;

  for (int i = 0; i < str.size(); ++i) {
    if (str[i] == '(' || str[i] == '[')
      s.push(str[i]);
    else {
      if (s.empty()) return false;
      char close_char = (str[i] == ')') ? '(' : '[';

      int elm = s.top(); s.pop();
      if (elm != close_char) return false;
    }
  }

  return s.empty();
}

int main() {
  int t;
  string s, endline;

  cin >> t;
  getline(cin, endline);

  while (t--) {
    getline(cin, s);

    if (balanced(s)) cout << "Yes" << endl;
    else cout << "No" << endl;
  }

  return 0;
}
