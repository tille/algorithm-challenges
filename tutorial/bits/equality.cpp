#include <iostream>
#include <string>

using namespace std;

int main() {
  int a, b;
  string ans;

  cin >> a >> b;

  if( !(a^b) ) {
    ans = "numbers are equal.";
  } else {
    ans = "numbers are not equal.";
  }

  cout << ans << endl;
}

