using namespace std;
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

class ScoringEfficiency{
public:
  double getPointsPerShot(vector <string> gameLog){
    int frees = 0, points, goals = 0, total = 0;
    for( int i = 0; i < gameLog.size(); ++i ){
      string attempt = gameLog[i];
      stringstream ss;
      ss << attempt;
      string word;

      ss >> word;
      if(word == "Made"){
        ss >> word;
        if(word == "free"){ 
          total++; frees++;
        }else{
          points = int(word[0]-'0'); goals++;
          total += points;
        }
      }else{
        ss >> word;
        if(word == "free") frees++;
        else goals++;
      }      
    }
    
    double ans = total/double((frees*0.5) + goals);
    return ans;
  }
};