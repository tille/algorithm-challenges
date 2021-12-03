#include <bits/stdc++.h>

using namespace std;

#define MAXN 1002

int f[MAXN];

void build_failure_function(const string &pattern) {
  f[0] = 0;
  int m = pattern.size();

  for (int i = 1; i < m; ++i) {
    f[i] = f[i-1];

    while (f[i] > 0 && pattern[f[i]] != pattern[i])
      f[i] = f[f[i] -1];

    if (pattern[f[i]] == pattern[i]) 
      f[i]++;
  }
}

bool kmp(const string &pattern, const string &text) {
  build_failure_function(pattern);

  int m = pattern.size();
  int n = text.size();
  int seen = 0;

  for (int i = 0; i < n; ++i) {
    while (seen > 0 && pattern[seen] != text[i])
      seen = f[seen - 1];

    if (pattern[seen] == text[i]) seen++;
    if (seen == m) return true;
  }

  return false;
}

int main() {
  string text, pattern;
  int q, t;

  cin >> t;
  while( t-- ) {
    cin >> text >> q;
    while( q-- ) {
      cin >> pattern;
      cout << (kmp(pattern, text) ? "y" : "n") << endl;
    }
  }
  return 0;
}
