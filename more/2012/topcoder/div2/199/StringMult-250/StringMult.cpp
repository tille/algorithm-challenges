using namespace std;
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <math.h>

class StringMult{
public:
  string times(string sFactor, int iFactor){
    if( !iFactor or sFactor=="" ) return "";
    else if(iFactor < 0){
      for( int i = 0; i < floor(sFactor.size()/2); ++i ) 
        swap(sFactor[i], sFactor[sFactor.size()-1-i]);
      string cpy = sFactor;
      for( int i = iFactor; i < -1; ++i)
        sFactor += cpy;
      return sFactor;      
    }else{
      string cpy = sFactor;
      while(--iFactor) sFactor += cpy;
      return sFactor;
    }
  }
};