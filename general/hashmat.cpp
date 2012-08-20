#include <iostream>

 using namespace std;

long long a, b, result;

 int main(){
    while( cin >> a >> b ){
        if (b>a) cout << b-a << endl;
        else cout << a-b << endl;
    }
    return 0;
 }
