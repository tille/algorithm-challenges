#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) \
  for (int i = int(a); i <= int(b); i++)

int n, j, episode; 
bitset<100001> seen;

int main() {
  scanf("%d", &n);

  // set as true every episode seen
  REP(i, 0, n - 1) {
    scanf("%d", &episode);
    seen[episode - 1] = true; 
  }

  // look for the first instance of a false element
  for(j = 0; seen[j]; ++j);
  printf("%d\n", j + 1);

  return 0;
}

