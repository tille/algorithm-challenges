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

  int t, n, num, sum, red, blue;
  cin >> t;

  while (t--) {
    red = blue = 0;
    
    cin >> n; sum = 0;
    for(int i = 0; i < n; ++i) {
      cin >> num;
      sum += num;
      red = max(red, sum);
    }

    cin >> n; sum = 0;
    for(int i = 0; i < n; ++i) {
      cin >> num;
      sum += num;
      blue = max(blue, sum);
    }

    cout << max(0, red + blue) << endl;
  }
  return 0;
}