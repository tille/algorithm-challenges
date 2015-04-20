#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> lanterns;

double generate(int l) {
  vector<double> radius;

  if(lanterns[0]!=0) radius.push_back( lanterns[0] );
  for( int i=0; i<lanterns.size()-1; ++i ) {
    int dist = lanterns[i+1] - lanterns[i];
    radius.push_back(dist/2.0);
  }
  if(lanterns[lanterns.size()-1]!=l) radius.push_back(l-lanterns[lanterns.size()-1]);

  double max_elm = -1;
  for( int i=0; i<radius.size(); ++i) {
    if (radius[i]>max_elm)
      max_elm = radius[i];
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

  cout << generate(l) << endl;

  return 0;
}
     
