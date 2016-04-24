vi match, vis;

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

// inside main()
  int MCBM = 0;
  match.assign(V, -1); // V is the number of vertices in bipartite graph

  REP(l, 0, leftSize - 1) {
    vis.assign(n, 0);
    MCBM += aug(l);
  }

