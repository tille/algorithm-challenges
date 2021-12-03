#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)

int main() {
  int t; cin >> t;

  while(t--) {
    int n, num;
    cin >> n;

    set<int> s;
    REP(i,0,n-1) {
      cin >> num;

      if ( s.count(num) ) num++;

      if ( !s.count(num) ) s.insert(num); // not required to ask if the number is not in S, 
      //because you can insert repeated numbers in a set and works the same
    }
    cout << s.size() << endl;
  }

  return 0;
}