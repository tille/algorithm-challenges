using namespace std;
#include <iostream>
#include <vector>

class Average{
public:
  int belowAvg(vector <int> math, vector <int> verbal){
    int acum = 0, ans = 0;
    
    for( int i = 0; i < math.size(); ++i ){
      acum += (math[i] + verbal[i]);
    }
    double avg = acum/double(math.size());
    
    for( int i = 0; i < math.size(); ++i ){
      if( (math[i] + verbal[i]) < avg ) ans++;
    }
    
    return ans;
  }
};