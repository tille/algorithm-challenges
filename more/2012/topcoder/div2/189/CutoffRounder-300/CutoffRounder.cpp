using namespace std;
#include <iostream>
#include <string>
#include <sstream>

class CutoffRounder{
public:
  int round(string num, string cutoff){
    stringstream ss;
    string decimalPart, intPart;
    int i = 0, ans;
    double intCutoff, intDec;
    
    while( i != num.size() and num[i] != '.' ) i++;

    intPart = num.substr(0,i);
    if( i != num.size() and i != num.size()-1 ){
      decimalPart = "0." + num.substr(i+1,num.size()-i-1);
    }else{
      decimalPart = "0";
    }
    cutoff = "0." + cutoff.substr(2,cutoff.size()-2);    
    
    ss << intPart << " " << cutoff << " " << decimalPart;
    ss >> ans >> intCutoff >> intDec;

    cout << ans << endl;
    cout << cutoff << endl;
    cout << intDec << endl;
    
    if( intDec > intCutoff ) return ++ans;
    else return ans;
    
  }
};