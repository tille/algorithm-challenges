#include <bits/stdc++.h>

using namespace std;

#define maxn 10002

bool isPrime(int n) {
    if (!n) return false;
    if (n <= 3) return true;

    if (n%2 == 0 || n%3 == 0) return false;

    for (int i = 5; i*i <= n; i=i+6)
        if (n%i == 0 || n%(i+2) == 0)
            return false;
    return true;
}

int main () {
    int t; cin >> t;

    while (t--) {
        int d;
        cin >> d;

        int p = 1, q;
        bool exit = false;
        while (!exit) {
            p++;
            if (p >= d + 1 && isPrime(p)) {
                q = p;
                while (!exit) {
                    q++;
                    if (q >= p + d && isPrime(q))
                        exit = true;
                }
            }
        }

        cout << p*q << endl;
    }
    return 0;
}