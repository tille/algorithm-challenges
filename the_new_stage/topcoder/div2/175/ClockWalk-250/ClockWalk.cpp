using namespace std;
#include <iostream>

class ClockWalk{
public:
  int finalPosition(string flips){
    int ini = 0, ans = 0;
    for( int i = 1; i <= flips.size(); ++i ){
      if( flips[i-1] == 'h' ) ans = (ans+i)%12;
      else{
        int temp = ans - i;
        if( temp < 0 ) ans = 12 - (-temp%12);
        else ans = temp;
      }
    }
    if( !ans ) return 12;
    else return ans;
  }
};
