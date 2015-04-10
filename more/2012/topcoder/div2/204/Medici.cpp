using namespace std;
#include <iostream>
#include <math.h>
#include <cmath>
#include <vector>

class Medici{
public:
  int winner(vector <int> fame, vector <int> fortune, vector <int> secrets){
    int max_score = 0, player = -1;
    for( int i = 0; i < fame.size(); ++i ){
      int res = min(secrets[i], min(fame[i], fortune[i]));
      if( res > max_score ){
        player = i;
        max_score = res;
      }else if( res == max_score ) player = -1;
    }
    return player;
  }
};