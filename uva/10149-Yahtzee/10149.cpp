#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii; 

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define TRmsi(c, it) for (msi::iterator it = (c).begin(); it != (c).end(); it++)

int d[5];
vector<int> rp;
int costs[13 * 13];

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

bool full_house(int r) {
  bool p1 = rp.size() == 2 && (costs[(r * 13) + (rp[0] - 1)] / rp[0]) > 1;
  bool p2 = rp.size() == 2 && (costs[(r * 13) + (rp[1] - 1)] / rp[1]) > 1;
  return p1 && p2;
}

void score(int r) {
  int tot = 0;
  rp.clear();
  sort(d, d + 5);
  set<int> vis;

  REP(rr, 0, 12) costs[(r * 13) + rr] = 0;

  REP(i, 0, 4) {
    costs[(r * 13) + (d[i] - 1)] += d[i];
    tot += d[i];
    if (!vis.count(d[i])) rp.push_back(d[i]);
    vis.insert(d[i]);
  }

  costs[(r * 13) + 6] = tot;
  if (three_of_a_kind()) costs[(r * 13) + 7] = tot;
  if (four_of_a_kind()) costs[(r * 13) + 8] = tot;
  if (five_of_a_kind()) costs[(r * 13) + 9] = 50;
  if (short_straight()) costs[(r * 13) + 10] = 25;
  if (long_straight()) costs[(r * 13) + 11] = 35;
  if (full_house(r)) costs[(r * 13) + 12] = 40;
}

#define N 13

class Hungarian {
  private:
    int n;
    int max_match;
    int cost[N*N];
    int costMin[N*N];

    vector<int> lx;
    vector<int> ly;
    vector<int> xy;
    vector<int> yx;
    vector<bool> S;
    vector<bool> T;
    int slack[N];
    int slackx[N];
    vector<int> prev;

    void update_labels() {
      int x, y, delta = 1 << 30;
      for (y = 0; y < n; y++) {
        if (!T[y]) {
          delta = min(delta, slack[y]);
        }
      }

      for (x = 0; x < n; x++) {
        if (S[x]) {
          lx[x] -= delta;
        }
      }

      for (y = 0; y < n; y++) {
        if (T[y]) {
          ly[y] += delta;
        }
      }

      for (y = 0; y < n; y++) {
        if (!T[y]) {
          slack[y] -= delta;
         }
      }
    }

    void init_labels() {
      lx.assign(n, 0);
      ly.assign(n, 0);

      for (int x = 0; x < n; x++) {
        for (int y = 0; y < n; y++) {
          int it = x * n + y;
          lx[x] = max(lx[x], cost[it]);
        }
      }
    }

    void add_to_tree(int x, int prevx) {
      S[x] = true;
      prev[x] = prevx;

      for (int y = 0; y < n; y++) {
        int it = x * n + y;
        if (lx[x] + ly[y] - cost[it] < slack[y]) {
          int it = x * n + y;
          slack[y] = lx[x] + ly[y] - cost[it];
          slackx[y] = x;
        }
      }
    }

    void augment() {
      if (max_match == n) {
        return;
      }

      int x, y, root;
      int q[N], wr = 0, rd = 0;

      S.assign(n, false);
      T.assign(n, false);
      prev.assign(n, -1);

      for (x = 0; x < n; x++) {
        if (xy[x] == -1) {
          q[wr++] = root = x;
          prev[x] = -2;
          S[x] = true;
          break;
        }
      }

      for (y = 0; y < n; y++) {
        int it = root * n + y;
        slack[y] = lx[root] + ly[y] - cost[it];
        slackx[y] = root;
      }

      while (true) {
        while (rd < wr) {
          x = q[rd++];

          for (y = 0; y < n; y++) {
            int it = x * n + y;

            if (cost[it] == lx[x] + ly[y] &&  !T[y]) {
              if (yx[y] == -1) {
                break;
              }

              T[y] = true;
              q[wr++] = yx[y];
              add_to_tree(yx[y], x);
            }
          }

          if (y < n) {
            break;
          }
        }

        if (y < n) {
          break;
        }

        update_labels();
        wr = rd = 0;

        for (y = 0; y < n; y++) {
          if (!T[y] &&  slack[y] == 0) {
            if (yx[y] == -1) {
              x = slackx[y];
              break;
            } else {
              T[y] = true;

              if (!S[yx[y]]) {
                q[wr++] = yx[y];
                add_to_tree(yx[y], slackx[y]);
              }
            }
          }
        }

        if (y < n) {
          break;
        }
      }

      if (y < n) {
        max_match++;

        for (int cx = x, cy = y, ty; cx != -2; cx = prev[cx], cy = ty) {
          ty = xy[cx];
          yx[cy] = cx;
          xy[cx] = cy;
        }

        augment();
      }
    }

    int getMax() {
      int ret = 0;
      max_match = 0;
      xy.assign(n, -1);
      yx.assign(n, -1);

      vector<int> ans(n, -1);
      int bonus = 0;
      init_labels();
      augment();

      for (int x = 0; x < n; x++) {
        int it = x * n + xy[x];
        ans[xy[x]] = cost[it];
        if (xy[x] < 6) bonus += cost[it];
        ret += cost[it];
      }

      // REP(i, 0, n - 1)
      //   cout << ans[i] << " ";
      // bonus = (bonus >= 63) ? 35 : 0;
      // cout << bonus << " " << ret + bonus << endl;

      return ret;
    }

  public:
    int max_optimal;
    int min_optimal;

    Hungarian(int size, int array[]) {
      n = size;
      int max_value = 0;

      for (int row = 0; row < n; ++row) {
        for (int col = 0; col < n; ++col) {
          int it = row * n + col;
          cost[it] = array[it];
          costMin[it] = array[it];
          max_value = max(max_value, array[it]);
        }
      }

      max_optimal = getMax();
    }
};

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  while (cin >> d[0]) {
    cin >> d[1] >> d[2] >> d[3] >> d[4];
    score(0);

    REP(i, 1, 12) {
      cin >> d[0] >> d[1] >> d[2] >> d[3] >> d[4];
      score(i);
    }

    Hungarian hungarian(13, costs);

    REP(i, 0, 12) {
      REP(j, 0, 12) {
        cout << costs[(i*13) + j] << " ";
      }
      cout << endl;
    }
    cout << endl;
  }
  return 0;
}

