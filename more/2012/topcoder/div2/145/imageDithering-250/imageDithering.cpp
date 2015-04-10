#include <iostream>
#include <vector>
#include <string>
#include <map>

typedef long long ll;

using namespace std;

class ImageDithering{
  
  public:
  int count( string dithered, vector<string> screen){
    map<int, int> visited;
    int ans = 0;

    for( int i = 0; i < dithered.size(); ++i ) visited[dithered[i] - 'A'] = 1;

    for( int i = 0; i < screen.size(); ++ i ){
      for( int j = 0; j < screen[0].size(); ++j ){
        if( visited[ screen[i][j]-'A' ] ) ans++;
      }
    }
    
    return ans;
  }
};