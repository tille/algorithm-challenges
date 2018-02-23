#include <iostream>
#include <cmath>

typedef long long ll;
using namespace std;

int main() {
    int a = 100000; int b = 10000;

    cout << a - b << endl; // 90000
    cout << (a - b) * (a - b) << endl; // -489934592
    cout << abs(a - b) * abs(a - b) << endl; // 8.1e+09
    cout << (90000 * 90000) << endl; // -489934592

    ll tales = ll(90000) * ll(90000);
    cout << tales << endl; // 8100000000

    return 0;
}