#include <iostream>
#include <string>

using namespace std;

class TireRotation{
  public:
  int getCycle(string initial, string current){
    for( int i = 1; i <= 4; ++i ){
      if ( initial == current ) return i;
      string cur = initial;
      cur[0] = initial[3];
      cur[1] = initial[2];
      cur[2] = initial[0];
      cur[3] = initial[1];
      initial = cur;
    }
    return -1;
  }
};