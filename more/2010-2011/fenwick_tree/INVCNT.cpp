#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>

#define ll long long

using namespace std;

const int maxn=10000000;
int tree[maxn];
vector<int> v;

void add(int i,int k){
  for(; i < maxn; i += i&-i ) tree[i] += k;
}

ll get(ll i){
  ll s = 0;
  for(; i > 0; i-=i&-i) s+=tree[i];
  return s;
}

int main(){
  int t,n,num;
  ll tot;

  cin >> t;

  for( int i = 0; i < t; ++i ){
    memset( tree,0,sizeof tree );
    v.clear(); tot = 0;
    cin >> n;

    for( int j = 0; j < n; ++j ){
      cin >> num;
      v.push_back(num);
    }
    for( int j = v.size()-1; j > -1; --j ){
      add(v[j],1);
      tot += get(v[j]-1); 
    }
    cout << tot << endl;
  }
  return 0;
}
