#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define maxn 1001

string fib[maxn];

string add(string a, string b) {
  if (a.size() < b.size()) swap(a, b);
  b = string(a.size() - b.size(), '0') + b;
  string ans = string(a.size(), '0');
  int carry = 0;

  for (int i = a.size() - 1; i >= 0; i--) {
    int digit = carry + (a[i] - '0') + (b[i] - '0');
    ans[i] = (digit % 10) + '0';
    carry = digit / 10;
  }

  if (carry) {
    char last_digit = carry + '0';
    ans = " " + ans;
    ans[0] = last_digit;
  }
  return ans;
}

void calc() {
  fib[0] = fib[1] = "1";
  REP(i, 2, maxn) fib[i] = add(fib[i - 1], fib[i - 2]);
}

int main() {
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL);
  ll n;

  calc();
  while (cin >> n) {
    cout << fib[n + 1] << endl;
  }

  return 0;
}

