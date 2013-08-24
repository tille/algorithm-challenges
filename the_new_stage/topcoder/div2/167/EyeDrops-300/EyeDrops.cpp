using namespace std;
#include <iostream>

class EyeDrops{
public:
  double closest(int sleepTime, int k){
    bool isPossible = (24.0/k) >= sleepTime;
    if( isPossible ) return (24.0/k)*60;
    else return ((24.0-sleepTime)/double(k-1))*60;
  }
};