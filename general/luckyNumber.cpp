#include <iostream>
#include <string.h>
#include <sstream>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <math.h>

using namespace std;

typedef long long ll;

ll lucky[ 8001 ];

ll pote(ll a, ll b){
    ll result = 1;
    for( ll i = 0; i < b; ++i ) result *= a;
    return result;
}

void init(){
    lucky[0] = 0; lucky[1] = 5; ll n = 1;
    for( int i = 2; i < 8001; ++i ){
        ll pos = pote( 2 , n-1 );
        ll avan = i - pos;
        if( avan != pos ){ lucky[ i ] = lucky[ avan ] + lucky[ pos ]; }
        else{
            n++;
            lucky[i] = pote( 5 , n );
        }
    }
}

int main(){
    init();
    int a;
    int t; cin >> t;
    while( t-- ){
        cin >> a;
        cout << lucky[a] << endl;
    }
    return 0;
}
