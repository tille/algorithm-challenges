#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii; 

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define TRmsi(c, it) for (msi::iterator it = (c).begin(); it != (c).end(); it++)

ll n, p, ra, rb, li, ri, next;
vector<ii> segs;
double pa, pb, ans;

int main() {
  cout << fixed << setprecision(7);

  cin >> n >> p; 
  REP(i, 0, n - 1) {
    cin >> li >> ri;
    segs.push_back(make_pair(li, ri));
  }

  ans = 0;
  REP(i, 0, n - 1) {
    ra = segs[i].second - (segs[i].first - 1);
    pa = (int(segs[i].second / p) - int((segs[i].first - 1) / p)) / double(ra);

    next = (i + 1 + n) % n;
    rb = segs[next].second - (segs[next].first - 1);
    pb = (int(segs[next].second / p) - int((segs[next].first - 1) / p)) / double(rb);
    ans += (pb * pa) + (pa * (1- pb)) + (pb * (1 - pa));
  }

  cout << ans*1000.0*2 << endl;
  return 0;
}

