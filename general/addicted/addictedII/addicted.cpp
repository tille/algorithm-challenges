#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

#define MAXN 100000
int arr[MAXN];

int main(int argc, char *argv[]){
  int t, n;
  string s;
  freopen(argv[1],"r",stdin);
  //freopen("addicted_out.txt","w",stdout);  
  cin >> t;
  while ( t-- ){
    cin >> n >> s;
    for(int i = 0; i<=n; ++i) arr[i] = 0;
    for(unsigned int j = 0; j < s.size(); ++j ){
      if(s[j] =='1') arr[0]++;
      else arr[1]++;
      sort(arr,arr+n);
    }
    cout << arr[0] << " " << arr[1] << endl;
  }
  return 0;
}
