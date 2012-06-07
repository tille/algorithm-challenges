#include<cstdio>

using namespace std;


int main(){
	int n,ans;
	int con=1;
	int sum=0;
	int m=0;
	while(scanf("%d",&sum)!=EOF){
		for(int i=1;i<4;i++){
			scanf("%d",&n);
			sum+=n;
		}
		if(sum>m){
			m = sum;
			ans = con;
		}
		con++;
	}
	printf("%d %d\n",ans,m);
	return 0;
}
