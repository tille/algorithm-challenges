using namespace std;
#include <iostream>
#include <vector>

class IBEvaluator{
public:
  vector <int> getSummary(vector <int> predictedGrades, vector <int> actualGrades){
    vector<int> counter(7, 0);

    for( int i = 0; i < predictedGrades.size(); ++ i){
      int pos = abs(actualGrades[i] - predictedGrades[i]);
      counter[pos]++;
    }
    
    for( int i = 0; i < counter.size(); ++ i)
      counter[i] = (double(counter[i])/predictedGrades.size())*100;

    return counter;
  }
};