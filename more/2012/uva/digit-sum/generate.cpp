#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
using namespace std;

#define ll long long

// std::string s = std::to_string(num);
// std::ios_base::sync_with_stdio(false);
// x^y = e^(y*ln(x))

ll pow_int(ll x, ll exp){
  ll res = 1;
  for ( ; exp; --exp) res *= x;
  return res;
}

int main(){
  std::ios_base::sync_with_stdio(false); 
  srand (time(NULL));
  // for( ll i = 1; i <= pow_int(10,9); i=i+rand() % 100000 + 1 ){
    for( ll j = 1; j <= pow_int(10,9); j=j+100 ){
      cout << 1 << " " << j << endl;
    }    
  // }
  return 0;
}