using namespace std;
#include <iostream>
#include <map>
#include <vector>

class Education{
public:
  int minimize(string desire, vector <int> tests){
    int acum = 0;
    map<string, double> grades;
    grades["A"] = 90.0;
    grades["B"] = 80.0;
    grades["C"] = 70.0;
    grades["D"] = 60.0;
    
    for( int i = 0; i < tests.size(); ++i ) acum += tests[i];
    if( acum/double(tests.size()+1) > grades[desire] ) return 0; 
    else{
      int rest = ((tests.size()+1) * int(grades[desire])) - acum;
      if( rest > 100 ) return -1;
      else return rest;
    }
  }
};