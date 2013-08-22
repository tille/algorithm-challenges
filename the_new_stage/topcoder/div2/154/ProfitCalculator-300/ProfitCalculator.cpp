#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

class ProfitCalculator{
  public:
  int percent(vector <string> items){
    double cost = 0, price = 0, cost_t, price_t;
    for( int i = 0; i < items.size(); ++i ){
      istreamstream ss(items[i]);
      ss >> cost_t >> price_t;
      cost+= cost_t; price += price_t;
    }
    return ((100.0*(price-cost))/cost);
  }
};