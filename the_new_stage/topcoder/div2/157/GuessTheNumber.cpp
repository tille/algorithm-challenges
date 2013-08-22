#include <iostream>

using namespace std;

class GuessTheNumber{
public:
  int noGuesses(int upper, int answer){
    int lower = 1, x = (upper+1)/2, counter = 1;
    
    while( x != answer ){
  
      if( x > answer )
        upper = x-1;
      if( x < answer )
        lower = x+1;
  
      x = (upper + lower)/2;
      counter++;
    }
    
    return counter;
  }
};