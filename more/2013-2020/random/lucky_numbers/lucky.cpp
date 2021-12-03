#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

string next_lucky(string num) {
  int i = 0;
  while( num[i] == '4' || num[i] == '7' && i < num.size() ) 
    i++;

  if( i == num.size() ) return num;

  while( num[i]-'0' >= 7 && i >= 0 )
    i--;

  for( int j = i+1; j < num.size(); j++ ) 
    num[j] = '4';

  if( i == -1 )
    num = string("4") + num;
  else {
    num[i] = ( num[i]-'0' >= 4 ) ? '7' : '4';
  }

  return num;
}

int main() {
  string L, R;
  int next, limit, result;

  cin >> L >> R;

  next = atoi( next_lucky(L).c_str() );
  limit = atoi( R.c_str() );

  result = ( next > limit ) ? -1 : next;
  cout << result << endl;

  return 0;
}
