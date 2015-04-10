#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool myfunction(int i,int j) { return (i>j); }

// struct myclass {
//   bool operator() (int i,int j) { return (i>j);}
// } myobject;

class DiskSpace{  

  public:      
    int minDrives(vector <int> used, vector <int> total){
      int acum = 0;
      sort(total.begin(), total.end(), myfunction );
    
      for( int i = 0; i < used.size(); ++i ){
        acum += used[i];
        if( i != 0 )
          total[i] += total[i-1];            
      }
    
      for( int i = 0; i < used.size(); ++i )
        if( acum <= total[i] ) return i+1;
    }
  
};