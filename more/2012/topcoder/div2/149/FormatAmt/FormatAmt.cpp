#include <iostream>
#include <sstream>

using namespace std;

class FormatAmt{
  public:
  string amount(int dollars, int cents){
    stringstream ss;
    ss << dollars;
    string cpy = ss.str();
    
    for( int i = 3; i < cpy.size(); i+=4 )
      cpy.insert( cpy.size() - i, "," );

    ss.str("");
    ss << cents;
    
    string ans1 = "$"+cpy+".0"+ss.str();
    string ans2 = "$"+cpy+"."+ss.str();
    
    return ( cents < 10 )?ans1:ans2;
  }
};