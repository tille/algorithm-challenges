#include <iostream>

using namespace std;

int main() {
  int n, result = 1, cont = 1;
  long long a;
  int dp[100002];

  cin >> n;

  for (int i=0; i<n; ++i) {
    cin >> dp[i];

    if (i>0) {
      if (dp[i] >= dp[i-1])
        result = max(++cont, result);
      else
        cont = 1;
    }
  }

  cout << result << endl;

  return 0;
}
