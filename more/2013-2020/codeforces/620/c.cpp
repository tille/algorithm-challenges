#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef map<string, int> msi;

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)

int n, num, segs, ini;
set<int> nums;
vi results;

int main() {
  scanf("%d", &n);
  ini = 1;
  segs = 0;

  REP(i, 0, n - 1) {
    scanf("%d", &num);
    if (nums.count(num)) {
      results.push_back(ini);
      results.push_back(i + 1);

      segs++;
      nums.clear();
      ini = i + 2;
    } else {
      nums.insert(num);
    }
  }

  if (!segs) {
    printf("-1\n");
  } else {
    if (nums.size()) {
      results[results.size() - 1] = n; 
    }

    printf("%d\n", segs);
    for (int i = 0; i < results.size(); i += 2) {
      printf("%d %d\n", results[i], results[i + 1]); 
    }
  }

  return 0;
}
