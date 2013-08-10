#include <iostream>
#include <vector>

using namespace std;

#define MAXN 5002
int times[MAXN][2];
long long intersects[MAXN];
long long n;
vector<int> res;

void input(){
  for( int i = 0; i < n; ++i ){
    cin >> times[i][0] >> times[i][1];
  }  
}

int have_intersect(int l1, int l2, int l3, int l4){
  bool p1 = l1 < l3 && l2 > l3;
  bool p2 = l1 < l4 && l2 > l4;
  bool p3 = l3<= l1 && l2 <= l4;
  
  if( p1 or p2 or p3 ) return 1;
  else return 0;
}

long long calc_intersects(){
  long long acum, tot=0;
  
  for( int i = 0; i < n; ++i ){
    acum = 0;
    for( int j = 0; j < n; ++j ){
      if( i != j ){
        int inc = have_intersect(times[i][0],times[i][1],times[j][0],times[j][1]);
        acum += inc;
      }
    }
    intersects[i] = acum;
    tot += acum;
  }
  return tot;
}

int main(){
  cin >> n;
  input();
  long long total_intersects = calc_intersects();
  long long tot = total_intersects/2;
  
  for( int i = 0; i < n; ++i ){
    if( tot - intersects[i] == 0 ){
      res.push_back(i+1);
    }
  }
  
  cout << res.size() << endl;
  for( int i = 0; i < res.size(); ++i ) cout << res[i] << " ";
  
  return 0;
}