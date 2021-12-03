#include <iostream>

using namespace std;

int calc(int max) {
  int cubes = 0;
  int n = 0;

  while( cubes<max ) {
    n++;
    cubes += (n*(n+1))/2;
  }
  
  return (cubes>max) ? n-1 : n;
}

int main() {
  int n;

  cin >> n;

  cout << calc(n) << endl;

  return 0;
}
