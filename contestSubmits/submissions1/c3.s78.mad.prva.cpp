#include <cstring>
#include <cstdio>
#include <string>

using namespace std;

char grid[50][50];

bool valid(int i,int j,int d){
  if(d==0){
    if(i==0 || grid[i-1][j] == '#') return true;
    else return false;
  }else{
    if(j==0 || grid[i][j-1] == '#') return true;
    else return false;
  }
}

bool cmp (string w,string ans){ 
  for(int i=0;i<min(w.size(),ans.size());i++){
    if(w[i]<ans[i]) return true;
    if(ans[i]<w[i]) return false;
  }
  if(w.size()<ans.size()) return true;
  return false;
}



int main(){
  int r,c;
  scanf("%d %d",&r,&c);
  for(int i=0;i<r;i++){
    scanf("%s",&grid[i]);
  }

  string ans;
  bool band = false;
  for(int i=0;i<r;i++){
    for(int j=0;j<c;j++){
      string w;
      //abajo
      w="";
      if(valid(i,j,0)){
	for(int k=i;k<r;k++){
	  if(grid[k][j]=='#')
	    break;
	  w+=grid[k][j];
	}
	if(w.size()>1){
	  //printf("w:%s ans:%s => %d\n",w.c_str(),ans.c_str(),cmp(w,ans));
	  //if(!band || cmp(w,ans)){
	  if(!band || lexicographical_compare(w.begin(),w.end(),ans.begin(),ans.end())){
	    ans = w;
	    band = true;
	  }
	}
      }

      //lado
      w="";
      if(valid(i,j,1)){
	for(int k=j;k<c;k++){
	  if(grid[i][k]=='#')
	    break;
	  w+=grid[i][k];
	}
	if(w.size()>1){
	  //printf("w:%s ans:%s => %d\n",w.c_str(),ans.c_str(),cmp(w,ans));
	  //if(!band || cmp(w,ans)){
	  if(!band || lexicographical_compare(w.begin(),w.end(),ans.begin(),ans.end())){
	    ans = w;
	    band = true;
	  }
	}
      }

    }
  }
  printf("%s\n",ans.c_str());

  return 0;
}
