#include<iostream>
#include<math.h>
#include<stdio.h>

using namespace std;

typedef long long ll;

ll t,n;

int main(){
    cin >> t;
    while( t-- ){
        cin >> n;
        ll acum = 0;
        //for( int i = 1; i < n; ++i ) acum += (i*(i+1))/2;
        ll result=(n*(n+2)*(2*n+1))/8;
        cout <<  result << endl;
    }
    return 0;
}
