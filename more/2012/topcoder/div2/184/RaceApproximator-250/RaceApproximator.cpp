using namespace std;
#include <iostream>
#include <cmath>
#include <math.h>
#include <stdio.h>

class RaceApproximator{
public:
  string timeToBeat(int d1, int t1, int d2, int t2, int raceDistance){
    int secs = t1*exp(log(t2/double(t1))*log(d1/double(raceDistance))/log(d1/double(d2)));
    int h = secs/3600;
    secs = secs%3600;
    int min = secs/60;
    secs = secs%60;

    char buffer[20];    
    sprintf(buffer, "%d:%.2d:%.2d",h,min,secs);
    return string(buffer);
  }
};