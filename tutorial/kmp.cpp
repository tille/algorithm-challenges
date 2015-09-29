#include <iostream>
#include <string>

using namespace std;

#define MAXN 1000

int f[MAXN];

void build_failure_function(string pattern) {
  f[0] = 0;

  for (int i = 1; i < pattern.size(); ++i) {
    f[i] = f[i-1];

    while (f[i] > 0 && pattern[f[i]] != pattern[i])
      f[i] = f[f[i] - 1];

    if (pattern[f[i]] == pattern[i])
      f[i]++;
  }
}

int kmp(string text, string pattern) {
  int seen = 0;
  int matches = 0;

  for (int i = 0; i < text.size(); ++i) {
    while (seen > 0 && text[i] != pattern[seen])
      seen = f[seen - 1];

    if (text[i] == pattern[seen]) seen++;

    if (seen == pattern.size()) {
      matches += 1; // match between [i-m+1, i]
      seen = f[seen - 1];
    }
  }
  return matches;
}

int main() {
  string text, pattern;
  cin >> text >> pattern;

  build_failure_function(pattern);
  cout << kmp(text, pattern) << endl;
  return 0;
}
