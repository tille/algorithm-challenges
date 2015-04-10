using namespace std;
#include <iostream>
#include <cmath>
#include <math.h>

class DinkyFish{
public:
  int monthsUntilCrowded(int tankVolume, int maleNum, int femaleNum){
    int limit = tankVolume*2, fishes = maleNum+femaleNum, couples = min(maleNum, femaleNum), cont = 0;
    while( fishes <= limit ){
      cont++;
      couples *= 2;
      fishes += couples;
    }
    return cont;
  }
};