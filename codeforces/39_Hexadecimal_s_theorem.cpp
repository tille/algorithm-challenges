#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define maxn 47

vector<int> fib(maxn);

void calc() {
    fib[0] = 0;
    fib[1] = 1;
    for (int i = 2; i < maxn; ++i) {
        fib[i] = fib[i-1] + fib[i-2];
    }
}

// I know the naive approach is (0 0 n)
// but how about if you can't use the 0?
int main() {
    ll n; cin >> n;
    calc();

    if (n < 3) cout << "0 0 " << n << endl;
    else {
        for (int i = 1; i < maxn; ++i) {
            for (int j = 1; j < maxn; ++j) {
                for (int k = 1; k < maxn; ++k) {
                    if (fib[i] + fib[j] + fib[k] == n) {
                        cout << fib[i] << " " << fib[j] << " " << fib[k] << endl;
                        return 0;
                    }
                }
            }
        }
    }
    return 0;
}