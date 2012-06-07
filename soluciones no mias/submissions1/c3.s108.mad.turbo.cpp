#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

void increase(vector<int> &tree, int k, int inc) {
  for (; k < (int)tree.size(); k |= k + 1)
    tree[k] += inc;
}

int query(const vector<int> &tree, int a, int b) {
  if (a == 0) {
    int sum = 0;
    for (; b >= 0; b = (b & (b + 1)) - 1)
      sum += tree[b];
    return sum;
  } else {
    return query(tree, 0, b) - query(tree, 0, a-1);
  }
}


int main(){
  int n, x;
  scanf("%d",&n);
  vector<int> tree(n+1), tree2(n+1);
  vector <int> v, ans(n+1), ans2(n+1);

  for(int i=0;i<n;i++){
    scanf("%d",&x);
    if(x>((n+1)/2))
      v.push_back(2*(n-x+1));
    else
      v.push_back(2*x-1);
  }

  for(int i=0;i<n;i++){
    //printf("%d:%d\n",v[i],i-query(tree,0,v[i]));
    ans[v[i]] = i-query(tree,0,v[i]);
    increase(tree,v[i],1);
  }
  int k=0;
  for(int i=n-1;i>=0;i--){
    //printf("%d:%d\n",v[i],k-query(tree2,0,v[i]));
    ans2[v[i]] = k-query(tree2,0,v[i]);
    increase(tree2,v[i],1);
    k++;
  }

  // for(int i=0;i<n;i++) printf("%d%c",v[i],i==n-1?'\n':' '); printf("\n");
  // for(int i=1;i<=n;i++) printf("%d%c",ans[i],i==n?'\n':' ');
  // for(int i=1;i<=n;i++) printf("%d%c",ans2[i],i==n?'\n':' ');

  for(int i=1;i<=n;i++) printf("%d\n",i%2?ans[i]:ans2[i]);
  
  
  return 0;
}
