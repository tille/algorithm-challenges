#include<stdio.h>
#include<iostream>
#include<map>

using namespace std;

typedef long long ll;

int n,t,a,sum;

int main(){
    scanf("%d",&t);
    while( t-- ){
       scanf("%d",&n);
       int a = sum = 1;
       while( sum < n ) sum+=(++a);
       int temp = (sum-n)+1;
       int temp2 = a-(sum-n);
       if( (a%2) == 0 ) printf("TERM %d IS %d/%d\n",n,temp2,temp);
       else printf("TERM %d IS %d/%d\n",n,temp,temp2);
    }
    return 0;
}
