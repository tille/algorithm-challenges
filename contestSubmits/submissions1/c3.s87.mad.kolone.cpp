#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
  int n1,n2,t;
  cin >> n1 >> n2;
  string s1,s2;
  cin >> s1;
  cin >> s2;
  cin >> t;
  reverse(s1.begin(),s1.end());

  
  vector<pair<char,bool> > v;
  for(int i=0;i<n1;i++) v.push_back(make_pair(s1[i],false));
  for(int i=0;i<n2;i++) v.push_back(make_pair(s2[i],true));
  // for(int index=0;index<v.size();index++)
  //   cout << v[index].second;
  // cout << endl;
  
  for(int ct=0;ct<t;ct++){
    for(int index=0;index<v.size()-1;index++){
      if(v[index].second) continue;
      if(v[index+1].second){
	swap(v[index],v[index+1]);
	index++;
      }
    }
  }

  for(int index=0;index<v.size();index++)
    cout << v[index].first;
  cout << endl;
  return 0;
}
