using namespace std;
#include <algorithm>
#include <iostream>
#include <iterator>
#include <sstream>
#include <fstream>
#include <cassert>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <map>
#include <set>

typedef long long ll;

class Time{
public:
    string whatTime(int seconds){
        int n = seconds;
        int horas = n/3600;
        n -= (horas*3600);
        int minutes = n/60;
        n -= (minutes*60);
        seconds = n;
        char result[9];
        sprintf(result,"%d:%d:%d",horas,minutes,seconds);
    }
}
