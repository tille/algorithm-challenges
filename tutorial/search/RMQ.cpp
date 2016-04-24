#include <iostream>
#include <math.h>

using namespace std;

#define SIZE 100004
typedef long long ll;

int st[SIZE][SIZE]; // this should be st[SIZE][log SIZE];
int arr[SIZE];


int pot(int x, int n){
  int result = 1;
  for( int i = 0; i < n; result *= x, ++i );
  return result;
}

void sparse_table(int n) {
  int i, j, first, second;

 //initialize st for the intervals with length 1
  for (i = 0; i < n; i++) st[i][0] = i;

  for (j = 1; 1 << j <= n; j++){
    for (i = 0; i + (1 << j) - 1 < n; i++){
      first = st[i][j - 1];
      second = st[i + (1 << (j - 1))][j - 1];
      st[i][j] = (arr[first] < arr[second])? first : second;
    }
  }
}

int RMQ(int pi,int pj){
  int k = log(double(pj-pi))+1;
  int temp = pj - (1<<k) + 1; // (1<<k) or pot(2,k);
  int first = st[pi][k];
  int second = st[temp][k];
  return ((first<=second)?first:second);
}

int main(){
  arr[0] = 2;
  arr[1] = 4;
  arr[2] = 3;
  arr[3] = 1;
  arr[4] = 6;
  arr[5] = 7;
  arr[6] = 8;
  arr[7] = 9; 
  arr[8] = 1;
  arr[9] = 7;
  sparse_table(10);
  cout << RMQ(2,4) << endl;
  return 0;
}