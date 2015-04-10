#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

#define p(a) cout << a << endl;


int nums[1000001];
int i, j, mayor, menor, sum = 1;


int calcular( long n ){

  int acum = 1;  

  while ( n != 1 ){
    if ( n%2 == 0 ) n = n/2;
    else n = (n*3)+1;
    acum++;
  }

  return acum;

}

int main(){

  while ( scanf("%d%d",&i,&j) != EOF ){
    sum = 1;

    if ( i>j ){ mayor = i; menor = j;
      }else{ mayor = j; menor = i; }

      for ( long a = menor; a <= mayor; a++ ){
        nums[a] = calcular(a);
        if ( nums[a] > sum ) sum = nums[a];
      }

      cout << i << " " << j << " " << sum << endl;
    }
    return 0;
  }
