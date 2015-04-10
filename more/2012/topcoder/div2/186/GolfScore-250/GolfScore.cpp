using namespace std;
#include <iostream>
#include <map>
#include <vector>
#include <string>

class GolfScore{
public:
  int tally(vector <int> parValues, vector <string> scoreSheet){
    map<string, int> d;
    int ans = 0;
    
    d["triple bogey"] = 3;
    d["double bogey"] = 2;
    d["bogey"] = 1;
    d["par"] = 0;
    d["birdie"] = -1; 
    d["eagle"] = -2;
    d["albatross"] = -3;

    for( int i = 0; i < parValues.size(); ++i ){
      if( scoreSheet[i] == "HOle in one" ){
        ans += 1;
      }else{
        ans += parValues[i]+d[scoreSheet[i]];
      }
    }
    
    return ans;
  }
};