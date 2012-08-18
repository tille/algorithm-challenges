#include <algorithm>
#include <iostream>
#include <iterator>
#include <sstream>
#include <fstream>
#include <cassert>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <map>
#include <set>
#include <iomanip>

using namespace std;

#define FOUR 4
#define MAXN 502

int sign,carry,min_size,max_size,s1,s2;
char oper[3] = {'+','-','*'};
string both[FOUR], result, mult[502];

bool is_sign(char c){
  for( int i = 0; i < 4; ++i ){
    if( c == oper[i] ){
      sign = i;
      return true;
    }
  }
  return false;
}

void print_spaces(string ss, int tam){
  for( int kk = 0; kk < tam-ss.size(); ++kk ) printf(" ");
  cout << ss << endl;
}

void print_mul(string ss, int tam, int i){
  for( int kk = 0; kk < tam-ss.size(); ++kk ) printf(" ");
  for( int j = 0; j < ss.size()-i; ++j ) printf("%c",ss[j]);
  //for( int jj = 0; jj < i; ++jj ) cout << " ";
  printf("\n");
}

void fill(){
  s1 = both[0].size(), s2 = both[1].size();
  min_size = min(s1,s2);
  max_size = max(s1,s2);
  int min = (s1<s2)?0:(s1>s2)?1:2;
  int complex = max_size-min_size;
  
  string s = ""; carry = 0;
  for( int i = 0; i<complex; ++i) s += "0";

  if(!min) both[0] = s + both[0];
  else if(min==1) both[1] = s + both[1];
}

char i_sum(int a, int b){
  int sm = a+b+carry;
  carry = (sm<10)?0:1;
  char r = (sm<10)?char(sm+'0'):char((sm-10)+'0');
  return r;
}

char i_sub(int a, int b, int i){
  int sb = a-b;
  if(sb>=0) return char(sb+'0');
  else{
    a+=10;
    both[0][i-1] = char((both[0][i-1]-'0')-1+'0');
    return char((a-b)+'0');
  } 
}

char i_mul(int a, int b, int i){
  int mt = a*b+carry;
  carry = (mt<10)?0:mt/10;
  char r = (mt<10)?char(mt+'0'):char((mt%10)+'0');
  return r;
}

void sum(){
  fill();
  for( int i = max_size-1; i>=0; --i) result = i_sum(both[0][i]-'0',both[1][i]-'0') + result;
  if(carry) result = char(carry+'0') + result;
}

string sus(){
  fill();
  for( int i = max_size-1; i>=0; --i) result = i_sub(both[0][i]-'0',both[1][i]-'0',i) + result;
  for( int i = 0; i < max_size; ++i ) if(result[i]!='0') return result.substr(i,result.size()-i);
  return "0";
}

void mul(){
  for( int i = s2-1; i>=0; --i){
    mult[(s2-1)-i] = ""; carry = 0;
    
    if(both[1][i]=='0') mult[(s2-1)-i] = "0";
    else{ 
      for( int j = s1-1; j>=0; --j){
        mult[(s2-1)-i] = i_mul(both[1][i]-'0',both[0][j]-'0',i) + mult[(s2-1)-i];
      }
    }
    if(carry) mult[(s2-1)-i] = char(carry+'0') + mult[(s2-1)-i];
    for( int k = 0; k < (s2-1)-i; ++k ) mult[(s2-1)-i] = mult[(s2-1)-i] + '0';
  
    if((s2-1)-i){ 
      both[0] = result; 
      both[1] = mult[((s2-1)-i)];
      result = "";
      sum();
      both[0] = both[2];
      both[1] = both[3];
      s1 = both[0].size(), s2 = both[1].size();
    }else{
      result = mult[(s2-1)-i];
    }
  }
  
  both[3] = '*' + both[3];
  int line_one = max(both[2].size(), both[3].size());
  int tot = max(result.size(),max(both[3].size(), both[2].size()));
  
  print_spaces(both[2],tot);
  print_spaces(both[3],tot);
  string line1 = "";
  
  if(both[3].size()==2){
    for( int i = 0; i <max(both[3].size(),result.size()); ++i ) line1 = line1 + "-";
    print_spaces(line1,tot);
    
  }else{
    for( int i = 0; i <max(both[3].size(),mult[0].size()); ++i ) line1 = line1 + "-";
    print_spaces(line1,tot);
  
    for( int i = 0; i < s2; ++i ) print_mul(mult[i],tot,i);
    string line2 = "";
    for( int i = 0; i <result.size(); ++i ) line2 += '-';
    print_spaces(line2,tot);
  }
  print_spaces(result,tot);
}

void calc(){
  both[2] = both[0];
  both[3] = both[1];
  result = "";
  s1 = both[0].size(), s2 = both[1].size();
  
  if(!sign){ 
    sum();
    
    both[3] = '+' + both[3];
    int tot = max(max(both[2].size(),both[3].size()), result.size());
    
    print_spaces(both[2],tot);
    print_spaces(both[3],tot);
    string line1 = "";

    for( int i = 0; i <tot; ++i ) line1 = line1 + "-";
    print_spaces(line1,tot);
    print_spaces(result,tot);    
    
  }else if(sign==1){ 
    result = sus();
    
    both[3] = '-' + both[3];
    int tot = max(max(both[2].size(),both[3].size()), result.size());
    
    print_spaces(both[2],tot);
    print_spaces(both[3],tot);
    string line1 = "";

    for( int i = 0; i <max(both[3].size(),result.size()); ++i ) line1 = line1 + "-";
    print_spaces(line1,tot);
    print_spaces(result,tot);
    
  }else{ 
    mul();
  }
}

int main(){
  int t, ident;
  scanf("%d",&t);;
  string s;
  while( t-- ){
    cin >> s;
    both[0] = both[1] = result = "";
    ident = carry = 0;
    for( int i = 0; i<s.size(); ++i ){
      if( is_sign(s[i]) ){
        ++ident;
        continue;
      }
      both[ident] += s[i];
    }
    calc();
    printf("\n");
  }
  
  return 0;
}