#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define vi vector<int>

const int maxn = 55;

vector<bool> is_prime(maxn, true);
vi primes;

void sieve() {
    is_prime[0] = is_prime[1] = false;

    for (int i = 2; i * i <= maxn; ++i) {
        if (is_prime[i]) {
            for (int j = i * i; j <= maxn; j += i) 
                is_prime[j] = false;
        }
    }
}

int custom_upper_bound(int val) {
    int l = 0, r = primes.size();
    while (l <= r) {
        int mid = l + (r - l) / 2;

        if (primes[mid] <= val) l = mid + 1;
        else r = mid - 1;
    }
    return primes[l];
}

int main() {
    int a, b, ans;
    cin >> a >> b;

    sieve();
    for (int i = 0; i < maxn; ++i) 
        if (is_prime[i]) primes.push_back(i);

    ans = custom_upper_bound(a);
    cout << (ans == b ? "YES" : "NO") << endl;

    return 0;
}