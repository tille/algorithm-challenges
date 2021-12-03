#include <bits/stdc++.h>

using namespace std;

#define ll long long

vector<pair<ll, ll> > lines;

int main() {
  ll n, xa, xb, bi, ki;

  cin >> n;
  cin >> xa >> xb;

  for (int i = 0; i < n; ++i) {
    cin >> ki >> bi;
    ll y1 = (ki * xa) + bi;
    ll y2 = (ki * xb) + bi;
    lines.push_back(make_pair(y1, y2));
  }

  sort(lines.begin(), lines.end());
  string ans = "no";

  for (int i = 1; i < lines.size(); ++i) {
    if (lines[i].second < lines[i-1].second) {
      ans = "yes";
      break;
    }
  }
  cout << ans << endl;

  return 0;
}
