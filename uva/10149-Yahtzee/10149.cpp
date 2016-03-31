#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define TRmsi(c, it) for (msi::iterator it = (c).begin(); it != (c).end(); it++)

struct state {
  int categorization[15], score, bitmask1, bitmask2, target;

  state() {
    score = bitmask1 = bitmask2 = 0;
    target = (1 << 13) - 1;
    REP(i, 0, 14) categorization[i] = -1;
  }

  bool perfect() {
    if (bitmask1 == target && bitmask2 == target) {
      int bonus = (categorization[6] >= 63) ? 35 : 0;
      categorization[13] = bonus;
      score += bonus;
      return true;
    }
    return false;
  }

  void add(int pj, int c, int value) {
    bitmask1 |= (1 << pj);
    bitmask2 |= (1 << c);
    categorization[c] = value;
    score += value;
  }

  bool operator < (const state &other) const {
    return score < other.score;
  }
};

map<state, int> memo;
int d[5], r = 0, target;
int cost[15][15];
state ans;
vector<int> rp;

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
  bool p1 = (n >= 4 && (rp[0] + 3) == rp[3]);
  bool p2 = (n == 6 && (rp[1] + 3) == rp[4]);
  return (p1 or p2);
}

bool long_straight() {
  return rp.size() == 5 && ((rp[0] + 4) == rp[4]);
}

bool full_house() {
  bool p1 = rp.size() == 2 && (cost[r][rp[0] - 1] / rp[0]) > 1;
  bool p2 = rp.size() == 2 && (cost[r][rp[0] - 1] / rp[1]) > 1;
  return p1 && p2;
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

int matching(state &cur) {
  if (memo[cur]) 
    return memo[cur];

  if (cur.perfect()) {
    if (cur.score > ans.score) 
      ans = cur; 
    return memo[cur] = cur.score;
  }

  int pj, c, res = -1;
  for (pj = 0; pj < 13; ++pj) 
    if (!(cur.bitmask1 & (1 << pj)))
      break;

  for (c = 0; c < 13; ++c) {
    if (!(cur.bitmask2 & (1 << c))) {
      state next = cur;
      next.add(pj, c, cost[pj][c]);
      res = max(res, matching(next));
    }
  }
  return memo[cur] = res;
}

int main() {
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL);

  while (cin >> d[0] >> d[1] >> d[2] >> d[3] >> d[4]) {
    round_score();

    if (r == 12) {
      memo.clear();
      state ini = state();

      ans = ini;
      cout << matching(ini) << endl;
    }
    r = (r + 1) % 13;
  }
  return 0;
}
