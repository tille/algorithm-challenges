using namespace std;
#include <algorithm>
#include <iostream>
#include <iterator>
#include <sstream>
#include <fstream>
#include <cassert>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <map>
#include <set>

#define MAXN 301

int arr[MAXN][MAXN];
int L,C,num,ans;
vector<int> rows, cols;

int calc(){
  rows.clear(); cols.clear(); ans = 0;
  vector<int> rows_location(L,0);
  vector<int> cols_location(C,0);
  
  for( int i = 0; i < L; ++i ){
    int value = arr[i][0]/C;
    rows.push_back(value);
    rows_location[value] = i;
  }

  for( int i = 0; i < C; ++i ){
    int value = arr[0][i]%C;
    cols.push_back(value);
    cols_location[value] = i;
  }
  
  for( int i = rows.size()-1; i > -1; --i ){
    if( rows[i] != i ){
      int temp = rows[i]; ans++;
      swap(rows[i], rows[rows_location[i]]);
      swap(rows_location[i], rows_location[temp]);
    }
  }

  for( int i = cols.size()-1; i > -1; --i ){
    if( cols[i] != i ){
      int temp = cols[i]; ans++;
      swap(cols[i], cols[cols_location[i]]);
      swap(cols_location[i], cols_location[temp]);
    }
  }
  
  return ans;
}

int main(){
  while( cin >> L >> C ){
    bool possible = true;
    for( int i = 0; i < L; i++ ){
      for( int j = 0; j < C; j++ ){
        cin >> num; num--;
        arr[i][j] = num;
        
        if(j && int(num/C) != int(arr[i][j-1]/C)){ 
          possible = false;
        }
        if(i && num%C != arr[i-1][j]%C){ 
          possible = false;
        }
      }
    }
    
    if(!possible) cout << '*' << endl;
    else cout << calc() << endl;
  }
  return 0;
}