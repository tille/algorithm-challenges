#include <bits/stdc++.h>

using namespace std;

#define MAXN 57

string s;
long long number_1s = 0;
long long C[MAXN][MAXN];

void binomial() {
  C[0][0] = 1;
  for (long long i = 1; i <= MAXN; ++i){
    for (long long j = 0; j <= MAXN; ++j) {
      C[i][j] = C[i-1][j];
      if (j > 0) C[i][j] += C[i-1][j-1];
    }
  }
}

// int tales;
long long g(long long i, long long j) {
  long long res;

  // if (!tales) 
    // cout << "i: " << i << " j: " << j << endl;

  if (i <= 0 || j <= 0) res = 0;
  else if (s[i] == '1') res = C[i-1][j] + g(i-1, j-1);
  else if (s[i] == '0') res = g(i-1, j);

  // tales = 1;

  return res;
}

long long f(long long i, long long j) {
  long long res = 0;
  // tales = 0;

  if (i < 1) return 0;
  for (long long k = 3; k <= i; k+=3) {
    res += g(i, k);
    // cout << i << " " << j << " " << g(i, k) << endl;
  }
  if (number_1s % 3 == 0) res++;

  return res;
}

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
  long long n, result;
  binomial();

  while (cin >> n) {
    to_binary(n);
    // cout << s << endl;
    result = f(s.size()-1, 3);
    printf("Day %lld: Level = %lld\n", n, result);
    // cout << result << endl;
  }

  return 0;
}
