#include <iostream>

using namespace std;

int main(){
  int t,result,num;
  cin >> t;
  while( t-- ){
    cin >> num;
    for( result=0; num!=0; result += num/5, num /= 5 );
    cout << result << endl;
  }
  return 0;
}