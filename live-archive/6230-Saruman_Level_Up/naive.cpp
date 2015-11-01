#include <bits/stdc++.h>

using namespace std;

int number_1s;
string s;

string to_binary(long long n) {
  string result = " ";
  string binary_digit;
  number_1s = 0;

  if ( n == 0 ) return "0";

  while( n != 0 ) {
    binary_digit = ( n%2 == 0 ) ? "0" : "1" ;
    result = result + binary_digit;
    if (binary_digit == "1") number_1s++;
    n = n/2;
  }
  s = result;
}

int main() {
  long long n, res;

  while (cin >> n) {
    res = 0;
    for (int i = 1; i <=n; ++i) {
      to_binary(i);
      if (!(number_1s%3)) res++;
    } 
    cout << res << endl;
  }
  return 0;
}
