typedef long long ll;
const int maxn = 10000;
ll ft[maxn];

ll get(int i) {
  ll s = 0;
  for(; i; i -= i&-i) s += ft[i];
  return s;
}

ll add(int i, int v) {
  for(; i < maxn; i += i&-i) ft[i] += v;
}

// initialize tree
memset(ft, 0, sizeof ft);
