using namespace std;
#include <iostream>

class CountGame{
public:
  int howMany(int x, int goal, int next){
    next--; x++;
    if( (goal-next) % (x) == 0 ) return -1;
    return (goal-next)%x;
  }
};