#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)

int d[5], r = 0, target;
int cost[15][15];
vi rp;
map<ii, vi> memo;

bool three_of_a_kind() {
  return (d[0] == d[2] or d[1] == d[3] or d[2] == d[4]);
}

bool four_of_a_kind() {
  return (d[0] == d[3] or d[1] == d[4]);
}

bool five_of_a_kind() {
  return d[0] == d[4];
}

bool short_straight() {
  int n = rp.size();
  bool p1 = (n == 4 && (rp[0] + 3) == rp[3]);
  bool p2 = (n == 5 && (rp[1] + 3) == rp[4]);
  bool p3 = (n == 5 && (rp[0] + 3) == rp[3]);
  return (p1 or p2 or p3);
}

bool long_straight() {
  return (rp.size() == 5) && ((rp[0] + 4) == rp[4]);
}

bool full_house() {
  if (rp.size() == 1) return true;
  if (rp.size() != 2) return false;

  int cnt[2] = {0, 0};
  REP(i, 0, 4) {
    if (d[i] == rp[0]) cnt[0]++;
    else cnt[1]++;
  }
  bool p1 = cnt[0] == 3 && cnt[1] == 2;
  bool p2 = cnt[1] == 3 && cnt[0] == 2;
  return p1 or p2;
}

void round_score() {
  int tot = 0;
  rp.clear();
  sort(d, d + 5);
  set<int> vis;

  REP(i, 0, 4) {
    cost[r][d[i] - 1] += d[i];
    tot += d[i];
    if (!vis.count(d[i])) rp.push_back(d[i]);
    vis.insert(d[i]);
  }

  cost[r][6] = tot;
  if (three_of_a_kind()) cost[r][7] = tot;
  if (four_of_a_kind()) cost[r][8] = tot;
  if (five_of_a_kind()) cost[r][9] = 50;
  if (short_straight()) cost[r][10] = 25;
  if (long_straight()) cost[r][11] = 35;
  if (full_house()) cost[r][12] = 40;
}

vi matching(int bitmask, int c) {
  ii key;
  vi ans(15, 0);
  map<ii, vi>::iterator it;

  if (bitmask == target)
    return ans;

  key = make_pair(bitmask, c);
  it = memo.find(key);

  if (it != memo.end())
    return it->second;

  for (int i = 0; i < 13; ++i) {
    if (!(bitmask & (1 << i))) {
      vi res = matching(bitmask | (1 << i), c - 1);
      res[c] = cost[i][c];
      res[14] += res[c];

      if (c == 5) {
        res[13] = (res[14] >= 63) ? 35 : 0;
        res[14] += res[13];
      }

      if (res[14] > ans[14]) ans = res;
    }
  }
  return memo[key] = ans;
}

int main() {
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL);

  while (cin >> d[0] >> d[1] >> d[2] >> d[3] >> d[4]) {
    REP(j, 0, 12) cost[r][j] = 0;
    round_score();

    if (r == 12) {
      memo.clear();
      target = (1 << 13) - 1;
      vi sol = matching(0, 12);

      REP(i, 0, 13) cout << sol[i] << " ";
      cout << sol[14] << endl;
    }
    r = (r + 1) % 13;
  }
  return 0;
}
