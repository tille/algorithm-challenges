using namespace std;
#include <iostream>
#include <vector>

class BettingMoney{
public:
  int moneyMade(vector <int> amounts, vector <int> centsPerDollar, int finalResult){
    int sum = 0;
    for( int i = 0; i < amounts.size(); ++i ){
      if( i == finalResult ) continue;
      sum += amounts[i];
    }
    sum = sum*100;
    int ans = sum-(amounts[finalResult] * centsPerDollar[finalResult]);
    return ans;
  }
};