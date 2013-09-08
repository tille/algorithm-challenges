using namespace std;
#include <iostream>
#include <stack>
#include <string>
#include <sstream>

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }

template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }

class NoOrderOfOperations{
public:
  int evaluate(string expr){
    stack<string> s;
    int n1, n2, res;
    string op;
    
    for( int i = 0; i < expr.size(); ++i ){
      if( isdigit(expr[i]) ){
        s.push(toStr(expr[i]));
      }else{
        n1 = toInt(s.top()); s.pop(); n2 = toInt(expr[i+1]);
        if( expr[i] == '+' ) res = n1+n2;
        else if( expr[i] == '-' ) res = n1-n2;
        else if( expr[i] == '*' ) res = n1*n2;
        else res = n1/n2;
        s.push(toStr(res));
        i+=1;
      }
    }

    while(s.size() > 1){
      n1 = toInt(s.top()); s.pop();
      op = s.top(); s.pop();
      n2 = toInt(s.top()); s.pop();
      if( op == "*" ) res = n1*n2;
      else res = n1/n2;
      s.push(toStr(res));
    }
    
    return (toInt(s.top()));
  }
};