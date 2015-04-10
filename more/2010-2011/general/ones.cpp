#include <iostream>

using namespace std;

int main(){
  long long num,cont,n;
  while( cin >> n ){
    num = cont = 1;
    while( true ){
      int temp = num/n;
      if( (temp * n) == num ){ 
        cout << cont << endl;
        break;
      }
      cout << num << endl;
      if(cont > 19) break;
      num *= 10, num++, cont++;
    }
  }
  return 0;
}