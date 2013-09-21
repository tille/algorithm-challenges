using namespace std;
#include <iostream>
#include <map>
#define ll long long

int main(){
  ll N, R, diver;
  map<int,int> divers;
  while( cin >> N >> R ){
    divers.clear();
    
    for( int i = 0; i < R; ++i ){
      cin >> diver;
      divers[diver] = 1;
    }
    
    ll num = 0;
    for( int i = 1; i <= N; ++i ){
      if( !divers[i] ){
        cout << i << " ";
        num++;
      }
    }
    if(!num) cout << '*';
    cout << endl;
  }
  return 0;
}