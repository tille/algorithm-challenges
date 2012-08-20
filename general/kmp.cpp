#include <iostream>
#include <stdio.h>
#include <vector>
#include <set>
#include <string.h>

using namespace std;

typedef long long ll;

string p, text;
bool tales;

void kmp( long *b ){
  int i = 0, j = 0;
  while( i <= text.size()-p.size() ){
    if( text[ i ] == p[ j ] ){
      int copy = i+1; j++;
      while( j < p.size() ){
        if( text[ copy ] == p[ j ] && j == p.size()-1 ){ printf("%d\n",i); i += (j)-b[ j+1 ]; j++; tales = true; }
        else if( text[ copy ] == p[ j ] && j != p.size()-1 ){ j++; copy++; }
        else{ i += (j)-b[ j+1 ]; j = p.size(); }
      }
      j = 0;
    }
    i++;
  }
}

void Kmp2( long *kmpNext ){
  ll i,j;
  i = j = 0;
  while (j < text.size()){
    while ( i > -1 && ( p[i] == 1 && text[j] != 1 ) ) i = kmpNext[i];
    i++; j++;
    if (i >= p.size()){
      printf("%d\n",j-i);
      i = kmpNext[i];
    }
  }
}

void kmp( long *kmpNext ){
  int j = i = 1;
  pos = 0;
  while( pos == 0 && i <= n {
    if( (text[j] == 1 && p[ i ] == 1) || p[ i ] == 0 ){
      j++;
      i++;
    }else{
      j = kmpNext[j]+1;
      if( j == 0 ){
        j = 1;
        i++;
      }
      if( j = p.size()+1 ){
        pos = i-m;
      }
    }
  }

  void preKmp( long *b ){
    ll i = 0, j = -1;
    b[ i ] = j;
    while( i<p.size() ){
      while( j>=0 && p[i] != p[j] ) j = b[j];
      i++; j++;
      b[i] = j;
    }
  }

  int main()
  {
    text = "011001011001";
    p = "100";
    long b[ p.size()+1 ];
    preKmp( b );
    Kmp2( b );
    return 0;
  }
