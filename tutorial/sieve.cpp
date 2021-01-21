#include <bits/stdc++.h>

using namespace std;

#define maxn 51

vector<bool> primes(true, 52);

void sieve (int n) {
    for (int i = 2; i*i <= n; ++i) {
        if (primes[i]) {
            for (int j = i*i; j <= n; j+=i) {
                primes[j] = false;
            }
        }
    }
}

// O(n*log(log(n))) 

int main () {
    int n = 30;
    sieve(n);

    for (int i = 2; i < n; ++i) {
        if (primes[i])
            cout << i << " ";
    }
    cout << endl;
    return 0;
}