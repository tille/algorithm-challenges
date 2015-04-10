#include <iostream>

using namespace std;

class Inchworm{
public:
  int lunchtime(int branch, int rest, int leaf){
    int ans = 0;
    for( int i = 0; i <= branch; i=i+rest )
      if( !(i%leaf) ) ans++;
      
    return ans;
  }
};