#include <iostream>
#include <string>

using namespace std;

#define MAXN 1000

int f[MAXN];

void build_failure_function(const string &pattern) {
  f[0] = 0;
  int m = pattern.size();

  for (int i = 1; i < m; ++i) {
    f[i] = f[i-1];

    while (f[i] > 0 && pattern[f[i]] != pattern[i])
      f[i] = f[f[i] - 1];

    if (pattern[f[i]] == pattern[i])
      f[i]++;
  }
}

int kmp(const string &text, const string &pattern) {
  int seen = 0;
  int matches = 0;
  int n = text.size();
  int m = pattern.size();

  build_failure_function(pattern);

  for (int i = 0; i < n; ++i) {
    while (seen > 0 && text[i] != pattern[seen])
      seen = f[seen - 1];

    if (text[i] == pattern[seen]) seen++;

    if (seen == m)
      matches += 1; // match between [i-m+1, i]
  }
  return matches;
}

int main() {
  string text, pattern;
  cin >> text >> pattern;
  cout << kmp(text, pattern) << endl;
  return 0;
}
