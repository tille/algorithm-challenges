using namespace std;
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

class RPG{
public:
  vector <int> dieRolls(vector <string> dice){
    vector<int> ans;
    int min_a=0, max_a=0, rolls_cant, die_sides;
    double average=0;
    
    for( int i = 0; i < dice.size(); ++i){
      int j = 0;
      while(dice[i][j] != 'd') j++;
      string rolls_cant_str = dice[i].substr(0,j);
      string die_sides_str = dice[i].substr(j+1, dice[i].size()-j-1);
      
      stringstream ss;
      ss << rolls_cant_str + " ";
      ss << die_sides_str;
      
      ss >> rolls_cant;
      ss >> die_sides;
      
      min_a += rolls_cant;
      max_a += rolls_cant*die_sides;
      average += ((rolls_cant*(die_sides+1))/double(2));
    }
    
    ans.push_back(min_a);
    ans.push_back(max_a);
    ans.push_back(average);
    return ans;
  }
};