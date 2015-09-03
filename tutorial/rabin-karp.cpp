#include <iostream>
#include <string>

using namespace std;

int rabin_karp(string text, string pattern) {
  int found = 0,
      m = pattern.size(),
      pattern_hash = hash(pattern);
      chunk_hash;

  for ( int i = 0; i+m < n; ++i ) {
    chunk_hash = hash(text[i..i+m]);
    if ( chunk_hash == pattern_hash ) {
      found = 1;
      break;
    }
  }
  return found;
}

int main() {
  string text = '';
  string pattern = '';

  int found = rabin_karp();
  cout << "pattern found on the text: " << found << endl;
  return 0;
}
