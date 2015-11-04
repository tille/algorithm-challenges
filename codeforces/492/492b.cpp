#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

vector<int> lanterns;

double generate(int l) {
  vector<double> radius;

  // calc radius points
  int max_elm = 2*max(lanterns[0], l-lanterns[lanterns.size()-1]);
  for( int i=0; i<lanterns.size()-1; ++i ) {
    max_elm = max(max_elm, lanterns[i+1] - lanterns[i]);
  }

  return max_elm;
}

int main() {
  int n, l, a;

  cin >> n >> l;

  while(n--) {
    cin >> a;
    lanterns.push_back(a);
  }

  sort(lanterns.begin(), lanterns.end());

  double rez = generate(l);

  // error precision doesn't work with cout

  // cout << rez/2.0 << endl;
  printf("%.10f\n",rez/2.0);

  return 0;
}
     
