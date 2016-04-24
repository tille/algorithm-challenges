struct Trie {
  struct node {
    int c;
    int a[28];
  };

  node g[maxn];
  int stateCount;

  Trie() {
    stateCount = 0;
    clear();
  };

  void clear() {
    g[stateCount].c = 0;
    memset(g[stateCount].a, -1, sizeof g[stateCount].a);
    stateCount++;
  }

  void add(string s) {
    int cur = 0;
    REP(i, 0, s.size() - 1) {
      int next = s[i] - 'a';

      if (g[cur].a[next] == -1) {
        g[cur].a[next] = stateCount;
        clear();
      }
      cur = g[cur].a[next];
      g[cur].c += 1;
    }
  }

  int query(string s) {
    int cur = 0;
    REP(i, 0, s.size() - 1) {
      int next = s[i] - 'a';
      if (g[cur].a[next] == -1) return 0;
      cur = g[cur].a[next];
    }
    return g[cur].c;
  }
};

usage:
Trie t;
t.add("bang");
t.add("banyo");
t.query("ban");
