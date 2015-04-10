using namespace std;
#include <iostream>
#include <vector>
#include <cmath>
#include <math.h>

class PassingGrade{
public:
  int pointsNeeded(vector <int> pointsEarned, vector <int> pointsPossible, int finalExam){
    int points = 0, percentage = finalExam;

    for( int i = 0; i < pointsEarned.size(); ++i ){
      points += pointsEarned[i];
      percentage += pointsPossible[i];
    }

    int ans = ceil((percentage*0.65) - points);
    if( ans < 0 ) return 0;
    if( ans > finalExam ) return -1;
    else return ans;
  }
};