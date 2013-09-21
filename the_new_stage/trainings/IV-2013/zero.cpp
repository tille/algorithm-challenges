using namespace std;
#include <iostream>

int main(){
  long long a,b,c; char ans;
  while( cin >> a >> b >> c ){
    if( a != b and a != c ) ans = 'A';
    else if( b != a and b != c ) ans = 'B';
    else if( c != a and c != b ) ans = 'C';
    else ans = '*';
    cout << ans << endl;
  }
  return 0;
}