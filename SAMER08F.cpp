#include <iostream.h>
#include <stdio.h>

using namespace std;

int main(){
    int n;
    while( scanf("%d",&n) && n ) cout << ((((2*n)+1))*n*(n+1))/6 << endl;
    return 0;
}
