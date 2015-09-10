#include <iostream>
#include <string>
#include <math.h>

using namespace std;

#define K 10000

int text_keys[K];

int hash( string pattern ) {
  double b = 101;
  double m = pattern.size()-1;
  int mirror_it;
  int hash_key = 0;

  for ( int it = 0; it < m; ++it ) {
    mirror_it = int( m ) - it;
    hash_key += int( pattern[it] ) * int( pow( b, mirror_it ) );
  }

  return hash_key;
}

void fill_text_keys( string text, int m ) {
  double b = 101;

  for( int it = 0; it+m <= m; ++it ) {
    if ( it == 0 ) 
      text_keys[0] = hash( text.substr(0, m) );
    else {
      int old_elm = text[it-m]-'0' * int( pow(b, m-1) );
      text_keys[it] = (( text_keys[it-1] - old_elm ) * b) + int( text[it] );
    }
  }
}

int rabin_karp( string text, string pattern ) {
  int found = 0,
      m = pattern.size(),
      pattern_hash = hash( pattern );

  fill_text_keys( text, m );

  for ( int i = 0; i+m <= text.size(); ++i ) {
    if ( text_keys[i] == pattern_hash ) {
      found = 1;
      break;
    }
  }
  return found;
}

int main() {
  // string text = '';
  string pattern = "123";

  // int found = rabin_karp();
  // cout << "pattern found on the text: " << found << endl;
  
  cout << hash( pattern ) << endl;
  
  return 0;
}
