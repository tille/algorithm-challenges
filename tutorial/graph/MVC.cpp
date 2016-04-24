vi match, vis, g[maxn];
vector<bool> seen;

int aug(int l) {
  if (vis[l]) return 0;
  vis[l] = 1;
  REP(j, 0, g[l].size() - 1) {
    int r = g[l][j];
    if (match[r] == -1 || aug(match[r])) {
      match[r] = l, match[l] = r;
      return 1;
  } }
  return 0;
}

void bfs(int r) {
  queue<int> q;
  q.push(r);

  seen[r] = true;
  while (q.size()) {
    int cur = q.front();
    q.pop();

    REP(j, 0, g[cur].size() - 1) {
      int l = g[cur][j];

      if (!seen[l]) {
        ans.push_back(l);
        seen[l] = true;
        if (match[l] != -1) {
          q.push(match[l]);
          seen[ match[l] ] = true;
        }
      }
    }
  }
}

// inside main()
  int MCBM = 0;
  match.assign(V, -1); // V is the number of vertices in bipartite graph

  REP(l, 0, leftSize - 1) {
    vis.assign(n, 0);
    MCBM += aug(l);
  }

  seen.assign(n, false);

  REP(r, leftSize, V - 1) { // all right nodes
    if (match[r] == -1) bfs(r);
  }

  REP(r, leftSize, V - 1) {
    if (!seen[r]) ans.push_back(r);
  }

  // ans.size() == MCBM -> konig theorem
  // ans[] contains vertex ids
