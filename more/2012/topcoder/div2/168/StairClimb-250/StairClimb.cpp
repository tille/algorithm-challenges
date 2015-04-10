using namespace std;
#include <iostream>
#include <vector>

class StairClimb{
public:
  int stridesTaken(vector <int> flights, int stairsPerStride){
    int ans = 0;
    for( int i = 0; i < flights.size(); ++i ){
      if( i ) ans+=2;
      int tot = int(flights[i]/stairsPerStride);
      ans += tot;
      if( (flights[i]%stairsPerStride) ) ans++;
    }
    return ans;
  }
};