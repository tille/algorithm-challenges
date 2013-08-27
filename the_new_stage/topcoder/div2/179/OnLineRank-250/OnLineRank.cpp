using namespace std;
#include <iostream>
#include <vector>

class OnLineRank{
public:
  int calcRanks(int k, vector <int> scores){
    int ans = 0;
    for( int i = 0; i < scores.size(); ++i ){
      for( int j = i; j>=0 and j>=(i-k); j-- ){
        if(scores[j] > scores[i]) ans++;
      }
      ans++;
    }
    return ans;
  }
};