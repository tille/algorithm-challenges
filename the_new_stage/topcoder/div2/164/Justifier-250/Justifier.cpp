#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <cmath>
#include <math.h>
#include <stdio.h>

using namespace std;

class Justifier{
public:
  vector<string> justify(vector<string> textIn){
    char empty[60];
    memset(empty, ' ', sizeof empty);
    string empty_ans(empty); 
    
    int max_n = 0;

    for( int i = 0; i < textIn.size(); ++i ){
      int temp = textIn[i].size();
      max_n = max(max_n, temp);
    }
    
    for( int i = 0; i < textIn.size(); ++i )
      textIn[i] = empty_ans.substr(0,max_n-textIn[i].size()) + textIn[i];
    
    return textIn;
  }
};