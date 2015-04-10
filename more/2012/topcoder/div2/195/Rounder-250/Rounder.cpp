using namespace std;
#include <iostream>

class Rounder{
public:
  int round(int n, int b){
    int lower = (n>=b)?n-(n%b):0; int greater = lower+b;
    cout << lower << " " << greater << endl;
    if( abs(n-lower) < abs(n-greater) ) return lower;
    else if( abs(n-greater) < abs(n-lower) ) return greater;
    else return greater;
  }
};