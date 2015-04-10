#include <iostream>

using namespace std;


class WidgetRepairs{
  public:
  int days(vector <int> arrivals, int numPerDay){
    
    int days = 0;
    amount = 0;
    
    for( int i = 0; i < arrivals.size(); ++i ){
      amount += arrivals[i];
      if( amount >= numPerDay ){ 
        amount -= numPerDay;
        days++;
      }else if( amount > 0 ){ 
        amount = 0;
        days++;
      }
    }
    
    if( amount > 0 ){
      days += (amount/numPerDay);
      if( (amount%numPerDay) > 0 ) days++;
    }
    
    return days;
  }
};