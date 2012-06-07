#include <cstdio>

using namespace std;

int main(){
  int n;
  scanf("%d",&n);
  int w = n/2;
  int h = n-w;
  ++w; ++h;
  printf("%d\n",w*h);

  return 0;
}
