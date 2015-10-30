#include <bits/stdc++.h>

using namespace std;

string s;
int number_1s;

int coef(int i, int j) {
  return 1;
}

int g(int i, int j) {
  int res;

  if (i == 0) res = 0;
  else if (s[i] == '1') res = coef(i-1, j) + g(i-1, j-1);
  else if (s[i] == '0') res = g(i-1, j);

  return res;
}

int f(int i, int j) {
  int res = 0;

  for (int k = 3; k <= j; ++k) res += g(i, k);
  if (number_1s % 3 == 0) res++;

  return res;
}

string to_binary( int n ) {
  string result = " ";
  string binary_digit;

  if ( n == 0 ) return "0";

  while( n != 0 ) {
    binary_digit = ( n%2 == 0 ) ? "0" : "1" ;
    result += binary_digit;
    n = n/2;
  }
  s = result;
}

int main() {
  int n;

  cin >> n;

  to_binary(n);

  return 0;
}
