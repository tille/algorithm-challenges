#include<bits/stdc++.h>
using namespace std;

int get_size(long long x) {
  int s = 0;
  while (x > 0) {
    x /= 2;
    s ++;
  }

  return s;
}

int main() {
  long long n;
  while (cin >> n) {
    int k;
    cin >> k;

    vector<int> v(k), pos(k);
    for (int i = 0; i < k; ++i) {
      int t;
      cin >> t;
      pos[i] = t;

      if ((1LL << t) & n) {
        v[i] = 1;
      }
      else {
        v[i] = 0;
      }
    }

    sort(v.begin(), v.end());

    long long ans = 0;
    int size1 = get_size(n);

    do {
      long long n2 = n;
      for (int i = 0; i < k; ++i) {
        bool one = (1LL << pos[i]) & n;
        if ( one != v[i] )
          n2 ^= (1LL << pos[i]);
      }

      int size2 = get_size(n2);
      if (n2 % 7 == 0 && size1 == size2) ans = max(ans, n2);
    } while (next_permutation(v.begin(), v.end()));


    cout << ans << endl;
  }

  return 0;
}
