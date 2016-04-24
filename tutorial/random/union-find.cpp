// initialize each node in its own set
void init(int n){
  for(int i = 0; i < n; ++i) p[i] = i;
}

// update members of a set and find its set id
int find(int u){
  return p[u] == u ? u : p[u] = find(p[u]);
}

// join two sets
void link(int u, int v){
  int a = find(u);
  int b = find(v);
  if (a != b) p[a] = b;
}
