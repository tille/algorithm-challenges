#include <iostream>

using namespace std;

class DivisorDigits{
  public:
  int howMany(int number){
    int cpy = number, ans = 0;
    while( cpy ){
      int temp_digit = cpy%10;
      if ( temp_digit && !(number % temp_digit) ) ans++;
      cpy /= 10;
    }
    return ans;
  }
};