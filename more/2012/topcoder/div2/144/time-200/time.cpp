#line 1 "Time.cpp"
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

using namespace std;

typedef long long ll;

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }

class Time {
	public:
	string whatTime(int seconds) {
    ll hours = seconds/3600;
    seconds %= 3600;
    ll minutes = seconds/60;
    seconds %= 60;
    return toStr(hours) + ":" + toStr(minutes) + ":" + toStr(seconds);
	}
};

// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor