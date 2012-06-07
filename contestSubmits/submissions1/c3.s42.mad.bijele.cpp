#include <cstdio>
#include <vector>

using namespace std;

int main(){
  int pieces[] = {1,1,2,2,2,8};
  int x;
  vector<int> v;
  for(int i=0;i<6;i++){scanf("%d",&x); printf("%d%c",pieces[i]-x,i==5?'\n':' ');}


  return 0;
}
