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

int score(vi &v, int i) {
  if (i > 0 && i < v.size()-1) {
    int hill = (v[i - 1] < v[i]) && (v[i] > v[i + 1]);
    int valley = (v[i - 1] > v[i]) && (v[i] < v[i + 1]);
    return hill + valley;
  }
  return 0;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  int t; cin >> t;
  while(t--) {
    int n; cin >> n;
    vi v(n);
    for (auto& x : v) cin >> x;
    int intimidation = 0, best = 0;
  
    REP(i, 1, n-1) {
      intimidation += score(v, i);

      set<int> candidates;
      candidates.insert(v[i - 1] - 1);
      candidates.insert(v[i - 1]);
      candidates.insert(v[i - 1] + 1);

      candidates.insert(v[i + 1] - 1);
      candidates.insert(v[i + 1]);
      candidates.insert(v[i + 1] + 1);

      int unchanged = v[i];
      int mini = score(v, i-1) + score(v, i) + score(v, i+1);
      int cur = mini;
    
      for (int val : candidates) {
        v[i] = val;
        mini = min(mini, score(v, i-1) + score(v, i) + score(v, i+1));
      }
      
      best = max(best, cur - mini);
      v[i] = unchanged;
    }
    cout << intimidation - best << endl;
  }
  return 0;
}
