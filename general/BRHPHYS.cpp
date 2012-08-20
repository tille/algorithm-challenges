#include <iostream>
#include <math.h>

using namespace std;

int main(){
  int n,a,b;
  char G;
  cin >> n;
  double x = 100.0/(double)n, res = 0;
  
  while( n-- ){
    cin >> a >> b;
    res += (double(b)/double(a));
  }
  res *= x;
  
  if( res >= 0 && res <= 59 ) G = 'F';
  else if( res >59 && res <= 69 ) G = 'D';
  else if( res >69 && res <= 79 ) G = 'C';
  else if( res >80 && res <= 89 ) G = 'B';
  else if( res >89 && res <= 100 ) G = 'A';
  
  cout << G << endl;
  return 0;
}