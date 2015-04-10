using namespace std;
#include <iostream>
#include <vector>

class Soccer{
public:
  int maxPoints(vector <int> wins, vector <int> ties){
    int ans = 0;
    for( int i = 0; i < wins.size(); ++i){
      int points = wins[i]*3 + ties[i];
      if(points > ans) ans = points;
    }
    return ans;
  }
};