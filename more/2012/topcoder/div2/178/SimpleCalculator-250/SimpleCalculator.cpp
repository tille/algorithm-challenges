using namespace std;
#include <iostream>
#include <sstream>
#include <ctype.h>

class SimpleCalculator{
public:
  int calculate(string input){
    int ini = 0, num1, num2;
    while( isdigit(input[ini]) ) ini++;
    stringstream ss;
    ss << input.substr(0,ini) + " ";
    ss << input.substr(ini+1, input.size()-ini );
    ss >> num1;
    ss >> num2;
    
    if( input[ini] == '*' ) return num1*num2;
    else if( input[ini] == '/' ) return num1/num2;
    else if( input[ini] == '+' ) return num1+num2;
    else return num1-num2;
  }
};