#include <iostream>
#include <string>
#include <cstring>

using namespace std;

#define MAXN 300
#define K 1000000007

int letters[MAXN];

int most_repeated_character(string s) {
  int max = -1, 
      max_counter = 1, 
      letter_index;

  for( int i = 0; i < s.length(); ++i ) {
    letter_index = int( s[i] );
    letters[letter_index] += 1;

    if( letters[letter_index] > max ) {
      
      max = letters[letter_index];
      max_counter = 1;
    
    } else if( letters[letter_index] == max ) {
      max_counter++;
    }
  }

  return (max * max_counter);
}

int custom_potentiation(int m, int n) {
  cout << m << "-" << n << endl;
  int left_part, result;

  if( n%2 == 0 ) {
    left_part = custom_potentiation(m, n/2);
    result = custom_potentiation( left_part, 2 );
  } else if( n == 1 ) {
    result = m;
  } else {
    left_part = custom_potentiation(m, n-1);
    result = ( ( left_part % K ) * ( m % K ) ) % K;
  }

  return result;
}

int main() {
  int n, k;
  string s;

  memset(letters, 0, sizeof letters);

  cin >> n >> s;

  k = most_repeated_character(s);
  cout << custom_potentiation(k, n) << endl;

  return 0;
}
