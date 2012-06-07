#include <iostream>

using namespace std;

int n, x, y;

int main(){
    while ( scanf("%d",&n) != EOF ){
        for( int i=0; i<n; ++i ){
            cin >> y >> x;
            if( y == x )  cout << ((x%2==0) ? 2*x : (2*x)-1) << endl;
            else if( y == x+2 ) cout << ((x%2==0) ? (2*x)+2 : (2*x)+1 ) << endl;
            else cout << "No Number" << endl;
        }
    }
    return 0;
}
