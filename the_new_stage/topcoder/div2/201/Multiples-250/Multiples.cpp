using namespace std;
#include <iostream>

class Multiples{
public:
  int number(int min, int max, int factor){
    int ans = 0;
    for( int i = min; i <= max; ++i ){
      if( !(i%factor) ) ans++;
    }
    return ans;
  }
};