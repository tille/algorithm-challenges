// taken from http://ninjacoders.blogspot.com.co/2014/03/uva-11254-consecutive-integers.html
// nice explanation <3

#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;

typedef long long int lli;
typedef vector<int> vi;

int main(){
  vector <lli> div;
  lli s,i;

  while(scanf("%lld",&s)){
    if(s<0) break;
    div.clear();

    lli limit = sqrt(s);

    for(i=1;i<=limit;i++) if(s%i == 0){
      if(i%2) div.push_back(i);
      if(i!=s/i && (s/i)%2) div.push_back(s/i);
    }

    lli n, m, a, b, v, u, diff=0, f_n, f_m;

    for(i=0;i<div.size();i++){
      a = div[i]; b = (2*s)/a;
      if(a>b) swap(a,b);

      v = a + b; u = b - a;
      n=((int)sqrt(8*s + u*u) - 1)/2;
      m=((int)sqrt(1 + 4*n*(n+1) - 8*s ) - 1)/2;

      if((n-m) > diff){
        diff=abs(n-m);
        f_n=n,f_m=m;
      }
    }
    printf("%lld = %lld + ... + %lld\n",s,f_m+1,f_n);
  }
  return 0;
}
