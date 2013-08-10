#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

#define SIZE 82
#define MAX_LCS 1005
typedef set<string> tt;

int lcs[SIZE][SIZE];
string A,B;
char path[MAX_LCS];
tt result;
tt::iterator it;

void lcs_calc(){
  for( int i = 1; i <= A.size(); ++i ){
    for( int j = 1; j <= B.size(); ++j ){
      if(A[i-1] == B[j-1]) lcs[i][j] = lcs[i-1][j-1]+1;
      else lcs[i][j] = max( lcs[i-1][j], lcs[i][j-1] );
    }
  }
}

void print_result(int m, int n, int len, int index){
  if(len==0) {
    string s="";
    for(int i = 0; i < index; i++ ) s = path[i] + s;
    result.insert(s);
    return;
  }
  
  for(char c = 'a'; c <= 'z'; c++ ) {
    int flag = 1;
    for(int i = m; i >= 0 && flag; i-- ) {
      if(A[i]!=c) continue;
      for(int j = n; j >= 0 && flag; j-- ) {
        if(B[j]!=c) continue;
        if(lcs[i+1][j+1]==len) {
          path[index]=c;
          print_result(i-1,j-1,len-1,index+1);
          flag=0;
        }
      }
    }
  }
}

int main(){
  int t;
  for(int i=0;i<SIZE;++i) lcs[i][0]=lcs[0][i]=0;

  cin >> t;
  while( t-- ){
    result.clear();
    cin >> A >> B;
    lcs_calc();
    int a_s = A.size(), b_s = B.size(); 
    print_result(a_s, b_s, lcs[a_s][b_s], 0);
    for(it=result.begin(); it!=result.end(); ++it) cout << *it << endl;
  }
  return 0;
}