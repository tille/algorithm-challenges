#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <stdlib.h>
#include <algorithm>

#define MAXN 101

using namespace std;

string pos, new_pos, side, s;
int cinema[MAXN][MAXN], row, col, Z, P, salir, r, c;
vector<string> t;

struct classcomp {
  bool operator() (string i, string j){
    int row_i = int(i[0]) - 65;
    int col_i = atoi( i.substr(1,i.size()).c_str() );

    int row_j = int(j[0]) - 65;
    int col_j = atoi( j.substr(1,j.size()).c_str() );

    if(row_j == row_i) return (col_j > col_i);
    else return (row_j > row_i);
  }
};

int main(){
  while( cin >> r >> c && r+c ){
    for(int i=0; i<=r+1; ++i) for(int j=0; j<=c+1; ++j) cinema[i][j] = 0;
    
    cin >> P;
    while( P-- ){
      cin >> pos >> side;
      row = int(pos[0]) - 65;
      col = atoi( pos.substr(1,pos.size()).c_str() );
      
      if( side == "-" ) col=col-1;
      cinema[row][col] = 1;
    }
    
    cin >> Z;
    map <string,int,classcomp> mapa;
    
    while( Z-- ){
      cin >> s;
      ++mapa[s];
    }
    
    salir = 0;
    map<string,int>::iterator it = mapa.begin();
    while(it != mapa.end() && !salir){

      new_pos = (*it).first;
      row = int( new_pos[0] ) - 65;
      col = atoi( new_pos.substr(1,new_pos.size()).c_str() );
      
      if(cinema[row][col-1] == 0) cinema[row][col-1] = 1;
      else if(cinema[row][col] == 0) cinema[row][col] = 1;
      else{
        salir = 1;
        break;
      }
      ++it;
    }
    cout << ((!salir)?"YES":"NO") << endl;
        
  }
  
  return 0;
}