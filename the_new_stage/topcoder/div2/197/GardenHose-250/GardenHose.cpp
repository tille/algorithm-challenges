using namespace std;
#include <iostream>

class GardenHose{
public:
  int countDead(int n, int rowDist, int colDist, int hoseDist){
    int cols = int(hoseDist/rowDist)*2, rows = int(hoseDist/colDist)*2;
    if( cols >= n or rows >= n ) return 0;
    else return (n-rows)*(n-cols);
  }
};