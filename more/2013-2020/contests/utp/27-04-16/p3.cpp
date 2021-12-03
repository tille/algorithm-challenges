#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)

int toDec(string s) {
  int ans = 0;
  reverse(s.begin(), s.end());
  REP(i, 0, s.size() - 1) {
    if (s[i] == '1') 
      ans += 1 << i;
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL);

  int tt; string s1, s2;
  cin >> tt;

  REP(i, 1, tt) {
    cin >> s1 >> s2;

    int n1 = toDec(s1);
    int n2 = toDec(s2);

    if (__gcd(n1, n2) != 1) 
      cout << "Pair #" << i << ": All you need is love!" << endl;
    else 
      cout << "Pair #" << i << ": Love is not all you need!" << endl;
  }
   
  return 0;
}

