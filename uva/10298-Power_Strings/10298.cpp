#include <bits/stdc++.h>

using namespace std;

#define MAXN 1000002

int f[MAXN];

void build_failure_function(const string &pattern) {
  int m = pattern.size();
  f[0] = 0;

  for (int i = 1; i < m; ++i) {
    f[i] = f[i-1];
    while (f[i] > 0 && pattern[i] != pattern[f[i]])
      f[i] = f[f[i] -1];

    if (pattern[i] == pattern[f[i]])
      f[i]++;
  }
}

int main() {
  string s;
  while (cin >> s && s != ".") {
    build_failure_function(s);

    int lon = s.size();
    int ans = 1;
    while (f[lon-1] > 0 && f[lon-1] >= lon/2) {
      if (f[lon-1]*2 == lon) ans = s.size()/f[lon-1];
      lon = f[lon-1];
    }
    cout << ans << endl;
  }

  return 0;
}
