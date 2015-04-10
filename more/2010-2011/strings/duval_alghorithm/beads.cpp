#include <iostream>
#include <string>

using namespace std;

string str;

int duval(){
  int i = 0, j = 1, l = 0, k, len = str.size();;
  // Invariant: i is the initial position of the smallest string before j
  while (j < len) { 
    for (k = 0; k < len && str[(i + k) % len] == str[(j + k) % len]; k++);
    if (k == len) break;  // all strings are equal    
    if (str[(i + k) % len] > str[(j + k) % len]) { 
      i = i + k + 1; // max( j, i+k+1 )
      j = i + 1;
    } else j += k + 1;
  }
  return i;
}

int duval2(){
  int i = 0, j = 1, k = 1, p = 1, a, b, l = str.size();
  while(j+k <= (l<<1)) {
    if ((a=str[(i+k-1)%l])>(b=str[(j+k-1)%l])) {
      i=j++;
      k=p=1;
    } else if (a<b) {
      j+=k;
      k=1;
      p=j-i;
    } else if (a==b && k!=p) {
      k++;
    } else {
      j+=p;
      k=1;
    }
  }
  return i;
}

int main(){
  int t;
  scanf("%d",&t);

  while(t--){
    cin >> str;
    printf("%d\n",duval()+1);
  }
  return 0;
}