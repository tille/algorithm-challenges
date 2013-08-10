using namespace std;
#include <algorithm>
#include <iostream>
#include <iterator>
#include <sstream>
#include <fstream>
#include <cassert>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <map>
#include <set>

#define ll long long

// std::string s = std::to_string(num);
// std::ios_base::sync_with_stdio(false);
// x^y = e^(y*ln(x))

ll pow_int(ll x, ll exp){
  ll res = 1;
  for ( ; exp; --exp) res *= x;
  return res;
}

ll count_digits( ll num, ll digit){
  ll prev = 0;
  ll ans = 0;

  stringstream ss;
  ss << num;
  string num_st = ss.str();

  for( ll i = 0; i < num_st.size(); ++i ){
    ll pos_int = num_st[i] - '0';
    ll rest = num_st.size()-i-1;

    ans += (prev) * pow_int(10,rest);
    
    if( pos_int > digit ) ans += pow_int(10,rest);
    if( pos_int == digit) ans += (num % pow_int(10,rest))+1;
    
    prev = (prev*10)+pos_int;
  }
  return ans;
}

int main(){
  ll n, m, cont_n, cont_m;
    
  while( cin >> n >> m && n+m ){
    cont_n = cont_m = 0; n--;
    
    for( ll i=1; i<=9; ++i){ 
      cont_n += i * count_digits(n,i);
      cont_m += i * count_digits(m,i);
    }
    cout << cont_m - cont_n << endl;
  }
    
  return 0;
}