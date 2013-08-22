#include <iostream>
#include <string>
#include <vector>

using namespace std;

class MostProfitable{
  public:
  string bestItem(vector <int> costs, vector <int> prices, vector <int> sales, vector <string> items){
    string item = ""; 
    int max_price = 0, profit;
    
    for( int i = 0; i < prices.size(); ++i ){
      profit = (prices[i]*sales[i]) - (costs[i]*sales[i]);
      if( profit > max_price ){
        item = items[i];
        max_price = profit;
      }
    }
    
    return item;
  }
};