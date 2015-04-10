using namespace std;
#include <iostream>
#include <vector>

class Swimmers{
public:
  vector <int> getSwimTimes(vector <int> distances, vector <int> speeds, int current){
    vector<int> ans;
    for( int i = 0; i < distances.size(); ++i ){
      if(!distances[i]) ans.push_back(0);
      else if(!(speeds[i]+current)) ans.push_back(-1);
      else if((speeds[i]-current) <= 0) ans.push_back(-1);
      else{
        double downstream = distances[i]/double(speeds[i]+current);
        double upstream = distances[i]/double(speeds[i]-current);
        ans.push_back(downstream+upstream);
      }
    }
    
    return ans;
  }
};