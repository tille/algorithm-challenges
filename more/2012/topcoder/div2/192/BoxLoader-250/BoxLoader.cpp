using namespace std;
#include <iostream>
#include <algorithm>

class BoxLoader{
public:
  int mostItems(int boxX, int boxY, int boxZ, int itemX, int itemY, int itemZ){
    int item[3] = { itemX, itemY, itemZ }; sort(item,item+3);
    int units, ans = 0;
    
    do{
      units = int(boxX/double(item[0])) * int(boxY/double(item[1])) * int(boxZ/double(item[2]));
      if(units > ans) ans = units;
    }while(next_permutation(item,item+3));
    
    return ans;
  }
};