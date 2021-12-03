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
const int M = 1e6;

string line, str;
msi h[MAXN];
int h_val, k, max_elm;

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
    REP(i, 0, MAXN - 1) h[i].clear();

    REP(i, 0, str.size() - 1) {
      h_val = 0;
      REP(j, i, str.size() - 1) {
        h_val = (((h_val * P) % M) + int(str[j])) % M;
        k = j - i + 1;
        h[k][h_val]++;
      }
    }

    k = 1;
    while (true) {
      max_elm = 0;
      TRmsi(h[k], it) {
        if (it->second > max_elm) 
          max_elm = it->second;
      }
      printf("%d\n", max_elm);
      if (max_elm == 1) break;
      k++;
    }
  }
  return 0;
}
