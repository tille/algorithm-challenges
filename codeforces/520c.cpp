#include <iostream>
#include <string>
#include <cstring>
#include <utility>

using namespace std;

#define MAXN 300
#define K 1000000007

int letters[MAXN];
int maxx, max_counter;

void most_repeated_character(string s) {
  maxx = -1;
  max_counter = 1;
  int letter_index;

  for( int i = 0; i < s.length(); ++i ) {
    letter_index = int( s[i] );
    letters[letter_index] += 1;

    if( letters[letter_index] > maxx ) {
      
      maxx = letters[letter_index];
      max_counter = 1;
    
    } else if( letters[letter_index] == maxx ) {
      max_counter++;
    }
  }
}

int cpot(int m, int n) {
  if( n%2 == 0 ) {
    return (n == 2) ? ( m%K * m%K )%K : cpot(m, n/2);
  } else {
    return (n == 1) ? m : (cpot(m, n-1)%K * m%K)%K;
  }
}

int main() {
  int n, k, result;
  string s;

  memset(letters, 0, sizeof letters);

  cin >> n >> s;

  most_repeated_character(s);
  result = (maxx==n) ? 1 : cpot(maxx*max_counter, n);

  cout << result << endl;

  return 0;
}
