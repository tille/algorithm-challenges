#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii; 
typedef map<int, int> msi;

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define TRmsi(c, it) for (msi::iterator it = (c).begin(); it != (c).end(); it++)

const int MAXN = 1005;
const int P = 997;
const int M = 1e5;

string line, str;
int h[MAXN][M];
int h_val, k, max_elm;
int ans[MAXN];

int c_pot(int n, int x) {
  int ans = 1;
  while (x--) ans = (ans * n) % M;
  return ans;
}

bool reading() {
  char c;
  str = "";
  while (1) {
    c = getchar();
    if (c == '\n') break;
    if (c != ' ') str += c;
  }
  return (str != "0");
}

int main() {
  while (reading()) {
    REP(i, 0, str.size() + 2) {
      ans[i] = 0;
      memset(h[i], 0, sizeof h[i]);
    }

    k = 0;
    while (1) {
      REP(i, 0, str.size() - 1) {
        if (i + k >= str.size()) break;
        ans[i] = (ans[i] + (int(str[i + k]) * c_pot(P, k)) % M) % M;
        h[k][ans[i]]++;
      }

      max_elm = *max_element(h[k], h[k] + M);
      printf("%d\n", max_elm);
      if (max_elm == 1) break;
      k++;
    }
  }
  return 0;
}

