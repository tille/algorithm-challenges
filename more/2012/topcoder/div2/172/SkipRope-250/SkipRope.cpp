using namespace std;
#include <iostream>
#include <cmath>
#include <math.h>
#include <vector>
#include <string>

class SkipRope{
public:
  vector <int> partners(vector <int> candidates, int height){
    int first = 0, second = 1;
    if( abs(candidates[1]-height) > abs(candidates[0]-height)) swap(first, second);
    
    for( int i = 2; i < candidates.size(); ++i ){
      int diff = abs(candidates[i]-height);
      int x = abs(candidates[first]-height);
      int y = abs(candidates[second]-height);

      if( diff < x or (diff == x and candidates[i]>candidates[first]) ){
        if( x < y or (x==y and candidates[first] > candidates[second]) ) second = first;
        first = i;
      }else if( diff < y or (diff == y and candidates[i]>candidates[second]) ) second = i;
    }

    vector<int> ans;    
    ans.push_back(min(candidates[first], candidates[second]));
    ans.push_back(max(candidates[first], candidates[second]));
    return ans;
  }
};