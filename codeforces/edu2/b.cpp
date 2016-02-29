#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii; 

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define TRmsi(c, it) for (msi::iterator it = (c).begin(); it != (c).end(); it++)

int n, m, num;
vector<int> a;

int min_search(int l, int r, int k) {
  while (l < r) {
    int mid = (l + r) / 2;
    if (a[mid] > k) r = mid;
    else l = mid + 1;
  }
  if (a[l] <= k) return r + 1;
  return l;
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  cin >> n >> m;

  REP(i, 0, n - 1) {
    cin >> num; a.push_back(num); }

  sort(a.begin(), a.end());
  int n = a.size();

  REP(i, 0, m - 2) {
    cin >> num;
    cout << min_search(0, n - 1, num) << " ";
  }
  cin >> num;
  cout << min_search(0, n - 1, num) << endl;

  return 0;
}
