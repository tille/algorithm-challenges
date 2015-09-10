#include <iostream>
#include <string>
#include <math.h>

using namespace std;

int hash( string pattern ) {
  double b = 101;
  double m = pattern.size()-1;
  int mirror_it;

  for ( int it = 0; it < m; ++it ) {
    mirror_it = int(m) - it;
    hash_key += pattern[it]-'0' * int( pow(b, mirror_it) );
  }

  return hash_key;
}

int text_hash( string text, int i, int m ) {
  int result;
  if ( i == 0 ) 
    result = hash( text.substr(0, m) );
  else {
    old_elm = text[i-m]-'0' * int( pow(b, mirror_it) );
    result = (( text_keys[i-1] - old_elm ) * b) + text[i]-'0';
  }

  return text_keys[i] = result;
}

int rabin_karp( string text, string pattern ) {
  int found = 0,
      m = pattern.size(),
      pattern_hash = hash( pattern );
      chunk_hash;

  for ( int i = 0; i+m <= text.size; ++i ) {
    chunk_hash = text_hash( text, i, m );
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
