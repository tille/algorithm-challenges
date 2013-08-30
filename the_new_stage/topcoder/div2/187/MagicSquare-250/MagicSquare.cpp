using namespace std;
#include <iostream>
#include <vector>

class MagicSquare{
public:
  int missing(vector <int> square){
    int rowNumber;
    int rowsSums[3] = {0,0,0};
    for( int i = 0; i < square.size(); ++i ){
      if( square[i] == -1 ) rowNumber = (i/3);
      rowsSums[int(i/3)] += square[i];
    }
    
    cout << rowsSums[0] << endl;
    cout << rowsSums[1] << endl;
    cout << rowsSums[2] << endl;

    if( rowNumber == 0 ) return (rowsSums[1]-(rowsSums[0]+1));
    else if( rowNumber == 1 ) return (rowsSums[2]-(rowsSums[1]+1));
    else return (rowsSums[0]-(rowsSums[2]+1));
    
  }
};