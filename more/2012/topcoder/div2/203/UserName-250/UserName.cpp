using namespace std;
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

class UserName{
public:
  string newMember(vector <string> existingNames, string newName){
    map<string,int> names;
    stringstream ss;
    int j=0;
    string ans = newName;

    for( int i=0; i<existingNames.size(); ++i ){
      names[existingNames[i]] = 1;
    }
    
    while(names[ans]){ 
      ss.str("");
      ss << ++j;
      ans = newName+ss.str();
    }
    return ans;
  }
};