using namespace std;
#include <iostream>
#include <algorithm>
#include <vector>


class Workshop{
public:
  int pictureFrames(vector <int> p){
    int ans = 0, r = 3, n = p.size();

    for( int i = 0; i <= n-r; ++i ){
      for( int j = i+1; j < n; ++j ){
        for( int k = j+1; k < n; ++k ){
          if( (p[i] + p[j]) > p[k] and (p[i] + p[k]) > p[j] and (p[j]+p[k]) > p[i] ) ans++;
        }
      }
    }

    return ans;
  }
};