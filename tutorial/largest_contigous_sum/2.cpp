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

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  long n;
  cin >> n;
  vector<long> a(n);
  REP(i,0,n-1) cin >> a[i];

  long best = LONG_MIN;
  REP(i,0,n-1) {
    long sum = 0;
    REP(j,i,n-1) {
      sum += a[j];
      best = max(best, sum);
    }
  }
  cout << best << endl;

  return 0;
}