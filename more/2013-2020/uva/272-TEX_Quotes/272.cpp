#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) \
  for (int i = int(a); i <= int(b); i++)

string s;
bool open = true;

bool replacing() {
  if (open) s.replace(s.find("\""), 1, "``");
  else s.replace(s.find("\""), 1, "''");
  open = !open;
}

int main() {
  string line;
  while (getline(cin, line)) {
    if (line == "") break;
    stringstream ss(line);
    int c = 1;
    while (ss >> s) {
      if (c > 1) cout << " ";
      while (s.find("\"") != string::npos) replacing();
      c++;
      cout << s;
    }
    cout << endl;
  }
  return 0;
}

