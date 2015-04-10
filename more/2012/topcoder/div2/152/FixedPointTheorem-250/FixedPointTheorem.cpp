#include <iostream>
#include <climits>
#include <float.h>

using namespace std;

class FixedPointTheorem{
  public:
  double cycleRange(double R){
    double X = 0.25;
    for( int i = 0; i < 200000; ++i ) 
      X = R*X*(1-X);
    
    double sup = DBL_MIN, inf = DBL_MAX;
    for( int j = 0; j < 1000; ++j ){
      X = R*X*(1-X);
      if( X > sup ) sup = X;
      if( X < inf ) inf = X;
    }
    
    return (sup-inf);
  }
};