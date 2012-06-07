#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <cassert>
#include <set>

using namespace std;

string p, text;

/*void kmp( long *b ){
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
}*/

void Kmp2( long *kmpNext ){
  int i,j;
  i = j = 0;
   while (j < text.size()){
      while (i > -1 && p[i] != text[j]) i = kmpNext[i];
      i++; j++;
      if (i >= p.size()){
         printf("%d\n",j-i);
         i = kmpNext[i];
      }
   }
}

vector<int> preKmp( int len ){
    vector<int> b;
    int i = 0, j = -1;
    b.push_back( j );
    while( i<p.size() ){
        while( j>=0 && p[i] != p[j] ) j = b[j];
        i++; j++;
        b.push_back( j );
    }
    return b;
}

int main() {
    int len, len2, caso = 1;
    scanf("%d",&len2);
    while( caso <= len2 ){
        scanf("%d",&len);
        cin >> p;
        cout << "Test case #" << caso++ << endl;
        vector<int> a = preKmp( len );
        for( int i = 2; i < len+1; ++i ){
            if( a[i] > 0 && i % (i-a[i]) == 0 ) printf("%d %d\n", i, i/(i-a[i]));
        }
        cout << endl;
    }
    return 0;
}
