#include <iostream>

using namespace std;

class LCMRange{
public:
  int lcm(int first, int last){
    for( int j = last; ; ++j ){
      int i;
      for( i = first; i <= last; ++i ){
        if( j%i != 0 ) break;
      }
      if( i == (last+1)) return j;
    }
  }
};