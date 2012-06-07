#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
  int n;
  long long int x,y;
  vector<pair<long long int,long long int> > v;
  scanf("%d",&n);
  for(int i=0;i<n;i++){
    scanf("%lld %lld",&x,&y);
    v.push_back(make_pair(x,y));
  }

  long long int cnt = 0;
  for(int i=0;i<n;i++){
    long long int x0=v[i].first, y0=v[i].second;
    //pii p0 = v[i];
    for(int j=i+1;j<n;j++){
      //pii p1 = v[i];
      long long int x1=v[j].first, y1=v[j].second;
      for(int k=j+1;k<n;k++){
	long long int x2=v[k].first, y2=v[k].second;
	//pii p2 = v[i];
	//if(ang(p0,p1,p2)) ans++;

	long long int p01 = (x0-x1)*(x0-x1) + (y0-y1)*(y0-y1);
	long long int p02 = (x0-x2)*(x0-x2) + (y0-y2)*(y0-y2);
	long long int p12 = (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
	if( (p01 == (p02+p12)) || (p02 == (p12+p01)) || (p12 == (p01+p02)) ) cnt++; 
      }
    }
  }
  printf("%lld\n",cnt);
  return 0;
}
