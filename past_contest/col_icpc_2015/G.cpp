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

complex<double> mul_complex_k( complex<double> n, int k ) {
  k--;
  while ( k-- ) 
    n += n;

  return n;
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

int main() {
  int p;
  string binary_num;
  complex<double> result;

  while( cin >> p ) {
    binary_num = to_binary( n );
    result = gx( "10" );
    cout << real(result) << " " << imag(result) << endl;
  }

  return 0;
}
