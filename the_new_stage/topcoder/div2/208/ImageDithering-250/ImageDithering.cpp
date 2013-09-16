using namespace std;
#include <iostream>
#include <vector>
#include <string>

class ImageDithering{
public:
  int count(string dithered, vector <string> screen){
    int ans = 0;
    for( int i = 0; i < screen.size(); ++i ){
      for( int j = 0; j < screen[i].size(); ++j ){
        if( dithered.find(screen[i][j]) != -1 ) ans++;
      }
    }
    return ans;
  }
};