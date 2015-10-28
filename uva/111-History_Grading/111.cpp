#include <bits/stdc++.h>

using namespace std;

#define MAXN 25

char a[MAXN];
char b[MAXN];

int main() {
  int n;
  string line;

  cin >> n;

  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  while (getline(cin, line) && line.size()) {
    stringstream ss(line);
    
    for (int i = 0; i < n; ++i) ss >> b[i];
  }

  return 0;
}
