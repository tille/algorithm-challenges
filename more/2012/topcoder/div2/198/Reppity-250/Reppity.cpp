using namespace std;
#include <cmath>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <climits>

class Reppity{
public:
  int longestRep(string input){
    int ans = 0;
    for( int i = 0; i < input.size()-1; ++i ){
      for( int j = 1; j+(i+j) <= input.size(); ++j ){
        string suffix = input.substr(i,j); 

        for( int k = j+i; k+j <= input.size(); ++k){
          string possix = input.substr(k,j);
          if( suffix == possix){
            ans = max(ans,j);
          } 
        }
      }
    }
    return ans;
  }
};