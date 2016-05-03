#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PI 3.14159265

int main() {
  cout << fixed << setprecision(12);
  double d, h, v, e;
  cin >> d >> h >> v >> e;
  
  double r = d / 2.0;
  double Ab = PI * (r * r);
  double delta = e - (v / Ab);

  if (delta >= 0 && h) 
    cout << "NO" << endl;
  else {
    cout << "YES" << endl;
    cout << h / abs(delta) << endl;
  }
  return 0;
}

