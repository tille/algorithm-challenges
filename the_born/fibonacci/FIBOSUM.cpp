#include <iostream>
#include <vector>
#include <set>

using namespace std;

#define LENGHT 5
#define K 1000000007
typedef long long ll;

// m^n = (m^(n-1))*m si n es inpar -> ((m^(k/2))^2)*m
// m^n = (m^(n/2))^2 si n es par

int ini[2][2] = { {0,1},{1,1} };
ll res[2][2] = { {0,1},{1,1} };
ll t,n,m,result;

void mul(int p){
  ll a,b,c,d;
  if(p){
    a = ( (res[0][0]%K * res[0][0]%K)%K + (res[0][1]%K * res[1][0]%K)%K )%K;
    b = ( (res[1][0]%K * res[0][0]%K)%K + (res[1][1]%K * res[1][0]%K)%K )%K;
    c = ( (res[0][0]%K * res[0][1]%K)%K + (res[0][1]%K * res[1][1]%K)%K )%K;
    d = ( (res[1][0]%K * res[0][1]%K)%K + (res[1][1]%K * res[1][1]%K)%K )%K; 
  }else{
    a = ( (res[0][0]%K*ini[0][0]%K)%K + (res[0][1]%K*ini[1][0]%K)%K )%K;
    b = ( (res[1][0]%K*ini[0][0]%K)%K + (res[1][1]%K*ini[1][0]%K)%K )%K;
    c = ( (res[0][0]%K*ini[0][1]%K)%K + (res[0][1]%K*ini[1][1]%K)%K )%K;
    d = ( (res[1][0]%K*ini[0][1]%K)%K + (res[1][1]%K*ini[1][1]%K)%K )%K; 
  }
  res[0][0] = a;
  res[1][0] = b;
  res[0][1] = c;
  res[1][1] = d;	
}

void elevar(long long n){
  if(n==1) return ;
  if(n%2){
    elevar(n-1);
    mul(0);
  }else{
    elevar(n/2);
    mul(1);
  }
}

ll fib(ll num){
  if(!num) return 0;
  else if(num==1) return 1;
  else{
    res[0][0]=0; res[0][1]=1; res[1][0]=1; res[1][1]=1;
    elevar(num-1);
    return res[1][1];
  }
}

int main(){
  cin >> t;
  while(t--){
    result = 0;
    cin >> n >> m;
    ll b = fib(m+2);
    ll a = fib(n+1);

    while(a>b){
      result = (result%K + fib(n)%K)%K;
      n++;
      a = fib(n+1);
    }

    result = (result%K + (b%K + (-a)%K )%K)%K;
    cout << result << endl;
  }
  return 0;
}