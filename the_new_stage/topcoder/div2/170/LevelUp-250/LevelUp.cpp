using namespace std;
#include <iostream>
#include <vector>

class LevelUp{
public:
  int toNextLevel(vector <int> expNeeded, int received){
    int i = 0; 
    while(received > expNeeded[i]){
      i++;
    }
    return (expNeeded[i]-received);
  }
};