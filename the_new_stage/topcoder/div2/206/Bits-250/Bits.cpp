using namespace std;
#include <iostream>
#include <math.h>
#include <cmath>

class Bits{
public:
  int minBits(int n){
    int ans = log(n)/log(2);
    return ++ans;
  }
};