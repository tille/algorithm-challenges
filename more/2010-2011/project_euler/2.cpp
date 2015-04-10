#include <iostream>

using namespace std;

#define SIZE 100000

int fib[SIZE];

int main(){
  long long res = 0;
  fib[0] = 0;
  fib[1] = 1;
  for( int i = 2;; ++i ){
    fib[i] = fib[i-2] + fib[i-1];
    if( fib[i] >= 4000000 ) break;
    else if( fib[i]%2 == 0 ){ 
      res += fib[i];
      cout << fib[i] << " " << i << endl;
    }
  }
  cout << res << endl;
  return 0;
}