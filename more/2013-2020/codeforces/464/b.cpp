#include <iostream>
#include <math.h>

using namespace std;

typedef long long ll;

int main() {
    ll n, m;
    cin >> n >> m;

    ll maxHamsters = 0;
    ll boxesCant = 0;
    int boxType = 1;
    ll ai;

    for (int i = 0; i < m; ++i) {
        cin >> ai;
        ll boxes = n / ai;
        ll hamsters = boxes * ai;

        if (hamsters > maxHamsters) {
            maxHamsters = hamsters;
            boxesCant = boxes;
            boxType = i + 1;
        }
    }

    cout << boxType << " " << boxesCant << endl;
    return 0;
}