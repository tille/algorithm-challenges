#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii; 

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define TRmsi(c, it) for (msi::iterator it = (c).begin(); it != (c).end(); it++)

vector<int> a;
int n, m, num;

int max_search(int l, int r, int k) {
  while (l < r) {
    int mid = (l + r + 1) / 2;
    if (a[mid] >= m) l = mid;
    else r = mid - 1;
  }
  return l;
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  cin >> n >> m;

  REP(i, 0, n - 1) {
    cin >> num;
    a.push_back(num);
  }

  sort(a.begin(), a.end());

  for (int i = a.size() - 2; i >= 0; --i) {
    a[i] = a[i] + a[i + 1];
  }

  cout << a.size() - max_search(0, a.size() - 1, m) << endl;
  return 0;
}

