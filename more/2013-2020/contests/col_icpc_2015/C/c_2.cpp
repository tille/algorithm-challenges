#include <iostream>
#include <string>

using namespace std;

#define MAXN 400002

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

int kmp(string pattern, string text) {
  int seen = 0;
  int matches = 0;

  build_failure_function(pattern);

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

string tree_gen(string exp) {
  string result = "";
  char node_label;

  int it = 0;
  while( it < exp.size() ) {
    if( exp[it] == '+' || exp[it] == '-' || exp[it] == '/' || exp[it] == '*') node_label = 'Y';
    else if( exp[it] == '(' || exp[it] == ')' ) node_label = exp[it];
    else node_label = 'X';

    if ( result.size() == 0 || 
        result[result.size()-1] != node_label ||
        node_label == '(' || node_label == ')' )
      result.push_back(node_label);
    it++;
  }

  return result;
}

int main() {
  string pattern, text;

  while( cin >> pattern >> text ) {
    pattern = tree_gen(pattern);
    text = tree_gen(text);

    cout << kmp(pattern, text) << endl;
  }
  return 0;
}
