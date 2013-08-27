using namespace std;
#include <iostream>
#include <vector>
#include <string>

class CrossWord{
public:
  int countWords(vector <string> board, int size){
    int cont = 0, ans = 0;
    for( int i = 0; i < board.size(); ++i ){
      cont = 0;
      for( int j = 0; j < board[i].size(); ++j ){
        if( board[i][j] == 'X' ){
          if( cont == size ) ans++;
          cont = 0;
        }else cont++;
      }
      if( cont == size ) ans++;
    }
    return ans;
  }
};