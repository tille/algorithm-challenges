using namespace std;
#include <iostream>
#include <vector>
#include <sstream>
#include <string>

template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }

class MovingAverages{
public:
  vector <int> calculate(vector <string> times, int n){
    vector<int> res; int ans;
    for( int i = 0; i <= times.size()-n; ++i ){
      ans = 0;
      for( int j = i; j < i+n; ++j ){
        ans += toInt(times[j].substr(0,2)) * 3600;        
        ans += toInt(times[j].substr(3,2)) * 60;        
        ans += toInt(times[j].substr(6,2));      
      }
      
      res.push_back( ans/double(n) );
    }
    
    return res;
  }
};