using namespace std;
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <math.h>
#include <cmath>

class OfficeParking{
public:
  int spacesUsed(vector <string> events){
    string action; int cont = 0, ans = 0;
    
    for( int i = 0; i < events.size(); ++i ){
      stringstream ss;
      ss << events[i];
      ss >> action; ss >> action;
      if( action == "arrives" ) cont++;
      else cont--;
      ans = max(ans,cont);
    }
    
    return ans;
  }
};