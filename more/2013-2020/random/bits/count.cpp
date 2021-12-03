#include <iostream>
#include <cmath>
using namespace std;

// int custom_count(int n) {
//   int q = 0; 
//   for (int i = 1; i < 32; i++) q += (n >> i) & 1;
//   return q;
// }

int std_count(int n) { return __builtin_popcount(n); }
int set(int n, int x) { return n | (1 << x); }
bool check(int n, int x) { return n & (1 << x); }
int toggle(int n, int x) { return n ^ (1 << x); }
int clear(int n, int x) { return n & ~(1 << x); }
int lsb(int n) { return log2(n & -n); }

int main() {
  cout << lsb(320) << endl;
  return 0;
}

