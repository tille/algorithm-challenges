#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
  int x;
  vector<int> v;
  char tmp[4];
  for(int i=0;i<3;i++){scanf("%d",&x); v.push_back(x);}
  scanf("%s",tmp);
  sort(v.begin(),v.end());
  for(int i=0;i<3;i++){printf("%d%c",v[tmp[i]-'A'],i==2?'\n':' ');}
  return 0;
}
