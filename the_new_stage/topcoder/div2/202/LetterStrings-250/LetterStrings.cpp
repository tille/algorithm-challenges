using namespace std;
#include <iostream>
#include <vector>

class LetterStrings{
public:
  int sum(vector <string> s){
    int ans = 0;
    for( int i = 0; i < s.size(); ++i ){
      for( int j = 0; j < s[i].size(); ++j ){
        if( s[i][j] != '-' ) ans++;
      }
    }
    return ans;
  }
};