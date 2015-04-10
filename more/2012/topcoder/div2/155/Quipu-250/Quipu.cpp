#include <iostream>
#include <string>

using namespace std;

class Quipu{
  public:
  int readKnots(string knots){
    int acum = 0, ans = 0;
    knots = knots.substr(1, knots.size()-1);
    for( int i = 0; i < knots.size(); ++i ){
      if( knots[i] == 'X' ) acum++;
      else{
        ans *= 10;
        if( acum ){ 
          ans += acum;
          acum = 0;
        }
      }
    }
    
    return ans;
  }
};