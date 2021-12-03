#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define maxn 1000000000

map<int, int> memo;
int n;

void calc(int acum, int i) {
  while (acum + i <= maxn) {
    acum += i;
    memo[acum] = i++;
  }
}

int main() {
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL);

  calc(0, 1);

  map<int, int>::iterator rest;

  while (cin >> n && n != -1) {
    for (int i = 0; i < n; ++i) {
      int b = (i * (i + 1)) / 2;
      rest = memo.find(b + n);
      if (rest != memo.end() && rest->second > i) {
        cout << n << " = " << i + 1 << " + ... + " << memo[b + n] << endl;
        break;
      }
    }
  }

  return 0;
}
// O(N log N) -> TLE
// solution runs in O(sqrt(n)) you can find it in this folder
