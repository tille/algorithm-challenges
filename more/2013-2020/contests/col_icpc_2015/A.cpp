#include <iostream> 
#include <string> 
#include <stdlib.h> 
#include <math.h>

using namespace std;

string mirror_pal(string d) {
  for( int i = 0; i < d.size()/2; ++i ) {
    int pos = d.size()-1-i;
    d[pos] = d[i];
  }
  return d;
}

bool is_greater(string a, string b) {
  if ( a.size() > b.size() )
    return true;
 
  int it = 0;
  while( a[it] == b[it] && it < a.size() )
    it++;
  
  return ( a[it]-'0' >  b[it]-'0' );
}

string string_inc( string a ) { 
  int i = a.size()-1;

  while( a[i] == '9' && i > -1 ) {
    a[i] = '0';
    i--;
  }

  if ( i == -1 ) 
    a = "1" + a;
  else
    a[i] = char( ( a[i]-'0' + 1 ) + '0' );

  return a;
}

string next_pal(string pal) {
  int limit = ceil( pal.size()/2.0 );

  string half_string = pal.substr( 0, limit );
  string second_half = pal.substr( limit, pal.size()-limit ); 

  string half_str_plus_1 = string_inc( half_string );

  return mirror_pal( half_str_plus_1 + second_half );
}

int main(){
  int n;
  string d;

  while( cin >> n >> d ) {
    string m = mirror_pal(d);
    
    while( !is_greater(m,d) ) m = next_pal(m);

    while( n-- ) {
     cout << m << endl;
     m = next_pal(m);
    }
  }

  return 0;
}
