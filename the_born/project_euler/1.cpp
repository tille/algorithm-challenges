#include <iostream>
#include <set>

using namespace std;

set<int> visited;
int res = 0;

int main(){
    
  for( int i = 3; i < 1000; i=i+3 ){
    if( visited.count(i) == 0 ){
      res += i;
      visited.insert(i);
    }
  }
  
  for( int j = 5; j < 1000; j=j+5 ){
    if( visited.count(j) == 0 ){
      res += j;
    }
  }
  
  cout << res << endl;
  return 0;
}