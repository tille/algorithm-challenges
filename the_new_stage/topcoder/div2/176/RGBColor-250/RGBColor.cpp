using namespace std;
#include <iostream>
#include <vector>

class RGBColor{
public:
  vector <int> getComplement(vector <int> rgb){
    vector<int> ans(3,0);
    int a = abs(rgb[0] - (255-rgb[0]));
    int b = abs(rgb[1] - (255-rgb[1]));
    int c = abs(rgb[2] - (255-rgb[2]));
    if( a <= 32 and b <= 32 and c <= 32 ){
      ans[0] = (rgb[0]>127)?rgb[0]-128:rgb[0]+128;
      ans[1] = (rgb[1]>127)?rgb[1]-128:rgb[1]+128;
      ans[2] = (rgb[2]>127)?rgb[2]-128:rgb[2]+128;
    }else{
      ans[0] = (255-rgb[0]);
      ans[1] = (255-rgb[1]);
      ans[2] = (255-rgb[2]);
    }
    return ans;
  }
};