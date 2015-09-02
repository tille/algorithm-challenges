#include <iostream>

using namespace std;

int lucky( int num ) {
  while( num ) {
    int t = num % 10;
    if ( t != 4 && t != 7 ) return 0;
    num = num / 10;
  }
  return 1;
}

int main() {
  for( int i =1; i<1000; ++i ) {
    int num = i;
    while( lucky(num) == 0 ) num++;
    cout << num << endl;
  }
  return 0;
}
