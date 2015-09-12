#include <iostream>
#include <string>
#include <math.h>

using namespace std;

#define K 10000

int text_keys[K];

int hashing( string pattern ) {
  double b = 101;
  double m = pattern.size()-1;
  int mirror_it;
  int hash_key = 0;

  for ( int it = 0; it <= m; ++it ) {
    mirror_it = int( m ) - it;
    hash_key += int( pattern[it] ) * int( pow( b, mirror_it ) );
  }

  return hash_key;
}

void fill_text_keys( string text, int m ) {
  double b = 101;

  for( int it = 0; it+m <= text.size(); ++it ) {
    if ( it == 0 ) 
      text_keys[0] = hashing( text.substr(0, m) );
    else {
      int old_elm = text[it-1] * int( pow(b, m-1) );
      text_keys[it] = (( text_keys[it-1] - old_elm ) * b) + int( text[it+m-1] );
    }
  }
}

int rabin_karp( string text, string pattern ) {
  int found = 0,
      m = pattern.size(),
      pattern_hash = hashing( pattern );

  fill_text_keys( text, m );

  for ( int i = 0; i+m <= text.size(); ++i ) {
    if ( text_keys[i] == pattern_hash ) {
      int j = i;

      // add 2-way verification since hash allow key collisions
      while( j < i+m && text[j] == pattern[j-i] )
        j++;

      if ( j == i+m ) 
        found += 1;
    }
  }
  return found;
}

int main() {
  string pattern = "123";
  string text = "312351231123";
  fill_text_keys(pattern, 3);

  int found = rabin_karp(text, pattern);
  cout << "pattern found on the text: " << found << endl;
  
  return 0;
}
