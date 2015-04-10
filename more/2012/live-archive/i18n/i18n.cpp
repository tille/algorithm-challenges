using namespace std;
#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <cmath>
#include <math.h>

map<string,string> dictionary;
map<char,int> separators;
map<string,int> ambiguous;

void fillSeparators(){
  char s[11] = {'-', ',', '.', '"', '(', ')', ':', ';', '!', '?', ' '};
  for( int i = 0; i < 11; ++i ){
    separators[s[i]] = 1;
  }
}

string convert_w(string word, int flag){
  for( int i=0; i<word.size(); ++i ){
    if(flag) word[i] = tolower(word[i]);
    else word[i] = toupper(word[i]);
  }
  return word;
}

void codify(string word){
  if( word.size() == 3 ) return ;
  
  stringstream ss;
  ss << word.size()-2;
  string nword = word[0] + ss.str() + word[word.size()-1];
  
  string ans = dictionary[nword];
  if( ans!="" and ans!=word ) ambiguous[nword]++;
  else dictionary[nword] = word;    
}

string calc(string word){
  if( word.size() < 3 ) return word;
  else{
    string lword = convert_w(word,1);
    if( word.size() >= 3 and isdigit(word[1]) ){

      string valid = dictionary[lword];
      if( valid != "" and ambiguous[lword] < 1 ){
        if(isupper(word[0]) && isupper(word[word.size()-1])) return convert_w(valid,0);
        else return string(word[0] + valid.substr(1,valid.size()-2) + word[word.size()-1]);
      }else return word;

    }else{
      codify(lword);
      return word;
    }
  }
}

int main(){
  string line, word, w_clean;
  fillSeparators();
  dictionary.clear(); ambiguous.clear();
  
  while( getline(cin,line) ){    
    stringstream ss;
    ss << line;
    
    for( int i = 0, pivot = 0; i <= line.size(); ++i ){
      if( separators[line[i]] || i == line.size() ){
        cout << calc( line.substr(pivot,i-pivot) );
        if( i == line.size() ) cout << endl;
        else cout << line[i];
        pivot = i+1;
      }
    }
  }
}