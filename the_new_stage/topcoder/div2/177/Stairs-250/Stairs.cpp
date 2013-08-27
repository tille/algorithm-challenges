using namespace std;
#include <iostream>

class Stairs{
public:
  int designs(int maxHeight, int minWidth, int totalHeight, int totalWidth){
    int ans = 0;
    for( int i = 1; i <= maxHeight; i++ ){
      if( !(totalHeight%i) ){
        int stairs = totalHeight/i;
        int treads = stairs-1;
        
        if(!treads) continue;
        if( !(totalWidth%treads) and int(totalWidth/treads) >= minWidth ){ 
          ans++;
        }
      }
    }
    
    return ans;
  }
};