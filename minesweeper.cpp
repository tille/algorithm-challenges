#include <iostream>
#include <string.h>
#include <sstream>
#include <fstream>
#include <cstdio>

using namespace std;
char M[102][102];

int f(int m, int n, int i, int j){
   int cont = 0;
   if ( M[i][j] == '*' ) return -1;
   if ( (i-1) > -1 && M[ i-1 ][ j ] == '*' ) cont++;
   if ( (j-1) > -1 && M[ i ][ j-1 ] == '*' ) cont++;
   if ( (j+1) < n && M[ i ][ j+1 ] == '*' ) cont++;
   if ( (i+1) < m && M[ i+1 ][ j ] == '*' ) cont++;
   if ( (i+1) < m && (j+1) < n && M[ i+1 ][ j+1 ] == '*' ) cont++;
   if ( (i-1) > -1 && (j+1) < n && M[ i-1 ][ j+1 ] == '*' ) cont++;
   if ( (i-1) > -1 && (j-1) > -1 && M[ i-1 ][ j-1 ] == '*' ) cont++;
   if ( (i+1) < m && (j-1) > -1 && M[ i+1 ][ j-1 ] == '*' ) cont++;
   return cont;
}

int main(){
    int m, n, cont = 0;
    while (scanf("%d %d",&m,&n) && m + m){
     for (int i = 0; i<m;++i){
      for (int j = 0; j<n;++j){
            cin >> M[i][j];
      }
     }
     if( cont != 0 ) cout << endl;
      cout << "Field #" << ++cont <<":" << endl;
      for( int i = 0; i<m; ++i ){
        for( int a = 0; a<n; ++a ){
            int result = f(m,n,i,a);
            if( result == -1 ){ cout << "*"; }
            else{ cout << result; }
        }
        printf("\n");
      }
    }
    return 0;
}
