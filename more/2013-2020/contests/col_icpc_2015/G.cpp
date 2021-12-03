#include <iostream>
#include <complex>
#include <string>

using namespace std;

complex<double> complex_pot( complex<double> n, int k ) {
  complex<double> result (1, 0);

  while( k-- )
    result *= n;

  return result;
}

complex<double> gx( string b ) {
  complex<double> CN (-1, 1);
  complex<double> acum (0, 0);
  complex<double> pot_k;

  for( int k = 0; k < b.size(); k++ ) {
    int bk = b[b.size()-1-k] - '0';
    pot_k = complex_pot( CN, k );

    if ( bk ) 
      acum += pot_k;
  }

  return acum;
}

string to_binary( int n ) {
  string result = "";
  string binary_digit;

  if ( n == 0 ) return "0";

  while( n != 0 ) {
    binary_digit = ( n%2 == 0 ) ? "0" : "1" ;
    result = binary_digit + result;
    n = n/2;
  }

  return result;
}

int main() {
  int p;
  string binary_num;
  complex<double> result;

  while( cin >> p ) {
    binary_num = to_binary( p );
    result = gx( binary_num );
    cout << real(result) << " " << imag(result) << endl;
  }

  return 0;
}
