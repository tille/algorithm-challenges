#include <iostream>
#include <vector>

using namespace std;

class BritishCoins{
public:
  vector <int> coins(int pence){
    vector<int> ans;
    int ans_pense = pence/240;
    pence %= 240;
    int ans_shiling = pence/12;
    pence %= 12;
    ans.push_back(ans_pense);
    ans.push_back(ans_shiling);
    ans.push_back(pence);
    
    return ans;
  }
};