#include <iostream>
#include <stdio.h>

using namespace std;

long long nums[ 100000 ], n, result;

int fibonacci( long n ){
    if ( nums[ n-1 ] == -1 ) nums[ n-1 ] = fibonacci( n-1 );
    nums[ n ] = nums[ n-1 ] + nums[ n-2 ];
    return nums[ n ];
}

int main(){
    nums[ 0 ] = 0;
    nums[ 1 ] = 1;
    for( int i = 2; i <= 100000; i++ ) nums[ i ] = -1;
    while ( scanf("%d",&n ) && n!= 0 ){
        result = fibonacci ( n );
        cout << result << endl;
    }
}
