using namespace std;
#include <iostream>
#include <vector>

class TransportCounting{
public:
  int countBuses(int speed, vector <int> positions, vector <int> velocities, int time){
    int final_pos = speed*time, ans = 0;
    for( int i = 0; i < positions.size(); ++i ){
      if( !positions[i] or (positions[i]+(velocities[i]*time)) <= final_pos ) ans++;
    }
    return ans;
  }
};

// {998, {1000, 1, 1000}, {997, 998, 0}, 999}