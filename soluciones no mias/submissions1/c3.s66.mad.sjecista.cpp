#include <cstdio>


using namespace std;


int main(){
  int n;
  scanf("%d",&n);
  int ans=0;
  for(int i=2;i<n;i++){
    for(int j=1;;j++){
      int tmp=n-i-j;
      if(!tmp) break;
      while(tmp){
	ans += tmp;
	tmp--;
      }
    }
  }
  printf("%d\n",ans);
  return 0;
}
