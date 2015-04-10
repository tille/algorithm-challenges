#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

int p[100];

class BinaryCode {
public:
  vector <string> decode(string);
};

string calc(string s,int r){
  
  if(s.size()==1){
    if(s[0]=='0' && r == 0) return "0";
    if(s[0]=='1' && r == 1) return "1";
    return "NONE";
  }
  
  memset(p,0,sizeof p);
  p[1] = r; string res = "";
  
  for( int i = 2; i <= s.size()+1; ++i ){
    p[i] = (s[i-2]-'0') - (p[i-1] + p[i-2]);
    if(p[i]!=0 && p[i]!=1) return "NONE";
    if(i!=(s.size()+1)) res += p[i]+'0';
  }
  if(p[s.size()+1] != 0) return "NONE";
  res = (!r)?"0"+res:"1"+res;
  return res;
  
}

vector <string> BinaryCode::decode(string message) {
  vector<string> res;
  res.push_back(calc(message,0));
  res.push_back(calc(message,1));
  return res;
}

int main(){
  string d = "111";
  cout << calc(d,0) << endl;
  cout << calc(d,1) << endl;
  return 0;
}