#include <algorithm>
#include <iostream>
#include <iterator>
#include <sstream>
#include <fstream>
#include <cassert>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <map>
#include <set>
#include <iomanip>

using namespace std;

template <class T> string to_str(const T &x)
{ stringstream s; s << x; return s.str(); }

int main(){
  int t = 1, cosa = 10e4-3,s_size;
  string s;
  freopen("addicted_in.txt","w",stdout);
  cout << t << endl;
  srand ( time(NULL) );

  for( int i = 0; i < t; ++i ){
    int n =rand()%cosa+3;
    cout << n << endl;

    s = "";
    s_size = (rand()%(cosa-n))+n;
    while(s_size--) s = s + to_str(rand()%2+1);
    cout << s << endl;
  }
  
  return 0;
}