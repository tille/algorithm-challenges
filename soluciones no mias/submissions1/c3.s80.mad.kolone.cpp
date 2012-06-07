#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
  int n1,n2,t;
  cin >> n1 >> n2;
  string s1,s2;
  cin >> s1;
  cin >> s2;
  cin >> t;
  reverse(s1.begin(),s1.end());

  int index1=0,index2=0;
  bool band = true;
  for(int index=0;index<n1+n2;index++){
    if(index1<n1-t) cout << s1[index1++];
    else{
      if(index1>=n1) cout << s2[index2++];
      else if(index2>=n2) cout << s1[index1++];
      else if(band && index2<n2){ cout << s2[index2++]; band = not band;}
      else{ cout << s1[index1++]; band = not band;}
    }
  }
  cout << endl;
  return 0;
}
