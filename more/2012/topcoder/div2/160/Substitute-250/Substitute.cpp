#include <iostream>
#include <string>
#include <map>
#include <cmath>
using namespace std;

#define ll long long

ll pow_int(ll x, ll exp){
  ll res = 1;
  for ( ; exp; --exp) res *= x;
  return res;
}

class Substitute{
public:
  int getValue(string key, string code){
    map<char, int> m;
    int ans = 1;

    for( int i = 0; i < key.size(); ++i )
      m[key[i]] = i+1;
    
    for( int j = 0; j < code.size(); ++j ){
      if( m[code[j]] ){
        ans *= 10;
        if(m[code[j]] != key.size()) ans += m[code[j]];
      }
    }
    
    int len = pow_int( 10, int(log10 ((double) ans) ) );
    return ans%len;
  }
};