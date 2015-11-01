// when operate long long values its terms must be long long too
// ex. ans = n-2 * n-2 
// then n must be long long

#include <bits/stdc++.h>

using namespace std;

int main() {
  long long ans;
  long long n;

  cin >> n;
  ans = (n-2) * (n-2);
  cout << ans << endl;
  return 0;
}

