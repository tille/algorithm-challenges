#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

const int inf = 1<<30;

int dr[] = {1,-1,0, 0,1,-1,-1, 1};
int dc[] = {0, 0,1,-1,1, 1,-1,-1};

void read(int i, vi &mn, vector<ll> &bags, ll &tot, vi &n) {
  REP(j,0,n[i]-1) {
    int num; 
    cin >> num;
    mn[i] = min(mn[i], num);
    bags[i] += num;
    tot += num;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  vi n(3);
  for (auto& x : n)
    cin >> x;

  vi mn(3, inf);
  vector<ll> bags(3, 0);
  ll tot = 0;

  REP(i,0,2)
    read(i, mn, bags, tot, n);

  sort(bags.begin(), bags.end());
  sort(mn.begin(), mn.end());

  ll ans1 = tot - (2 * (mn[0] + mn[1]));
  ll ans2 = tot - (2 * bags[0]);

  cout << max(ans1, ans2) << endl;

  return 0;
}