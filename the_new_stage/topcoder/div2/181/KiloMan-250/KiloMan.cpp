using namespace std;
#include <iostream>
#include <vector>

class KiloMan{
public:
  int hitsTaken(vector <int> pattern, string jumps){
    int ans;
    for( int i = 0; i < pattern.size(); ++i ){
      if(jumps[i]=='J' and pattern[i] > 2) ans++;
      else if(jumps[i]=='S' and pattern[i] <= 2) ans++;
    }
    return ans;
  }
}