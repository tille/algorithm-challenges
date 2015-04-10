using namespace std;
#include <iostream>
#include <vector>

class ProgressBar{
public:
  string showProgress(vector <int> taskTimes, int tasksCompleted){
    int completed = 0, tot = 0;
    for( int i = 0; i < taskTimes.size(); ++i ){
      if( i < tasksCompleted ) completed += taskTimes[i];
      tot += taskTimes[i];
    }
    
    double percentage = completed/double(tot);
    int ans = 20.0*(percentage);

    string bar = ".....................";
    string nums = "#####################";
    string result = (nums.substr(0,ans)+bar.substr(0,20-ans));
    return result;
  }
};

// int main(){
//   int m[] = {19,6,23,17};
//   vector<int> t(m, m+4);
//   showProgress(t, 3);
//   return 0;
// }