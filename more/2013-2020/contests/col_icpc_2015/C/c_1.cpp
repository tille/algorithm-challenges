// this solution was made for the problem
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=862&problem=4821&mosmsg=Submission+received+with+ID+16161273
// however it is getting TLE since rabin_karp algorithm is not enough faster here
// right approach must use KMP or similar O(n+m) algorithm in terms of complexity.

#include <iostream>
#include <string>
#include <math.h>

using namespace std;

#define K 10000
#define C 15000

int text_keys[K];

// correctly calculates a mod b even if a < 0
int int_mod(int a, int b) {
  return (a % b + b) % b;
}

int custom_pot(int x, int n) {
  int result = 1;
  
  while( n-- )
    result = (result * (x % C)) % C;

  return result;
}

int hashing( string pattern ) {
  int b = 101;
  int m = pattern.size()-1;
  int mirror_it;
  int hash_key = 0;
  int new_value;

  for ( int it = 0; it <= m; ++it ) {
    mirror_it = m - it;
    hash_key += (int(pattern[it]) % C * custom_pot(b, mirror_it) % C) % C;
  }

  return hash_key % C;
}

void fill_text_keys( string text, int m ) {
  int b = 101;

  for( int it = 0; it+m <= text.size(); ++it ) {
    if ( it == 0 ) 
      text_keys[0] = hashing( text.substr(0, m) );
    else {
      int old_elm = (int(text[it-1]) * custom_pot(b, m-1) % C) % C;
      text_keys[it] = (( int_mod(text_keys[it-1] - old_elm, C) * b) % C + int( text[it+m-1] )) % C;
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

    cout << rabin_karp(text, pattern) << endl;
  }
  return 0;
}
