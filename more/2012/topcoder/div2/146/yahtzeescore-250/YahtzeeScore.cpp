#include <iostream>
#include <vector>
#include <stdio.h>
#include <string.h>

using namespace std;

class YahtzeeScore{
  public:
  int maxPoints(vector <int> toss){
    int nums[7], ans = 0;
    memset(nums,0,sizeof nums);
    
    for( int i = 0; i < toss.size(); ++i ){
      nums[toss[i]] += toss[i];
      ans = max(ans,nums[toss[i]]);
    }
    
    return ans;
  }
};