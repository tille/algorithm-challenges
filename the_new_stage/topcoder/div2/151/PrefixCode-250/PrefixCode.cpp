#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>

using namespace std;

class PrefixCode{
  public:
  string isOne(vector <string> words){
    char buffer[30];
    
    for( int i = 0; i < words.size(); ++i ){
      for( int j = 0; j < words.size(); ++j ){
        if( i==j ) continue;
        if( words[i].size() <= words[j].size() and words[i] == words[j].substr(0,words[i].size()) ){          
          sprintf (buffer, "No, %d", i);
          string tt(buffer);
          return tt;
        }
      }
    }
    
    return "Yes";
  }
};