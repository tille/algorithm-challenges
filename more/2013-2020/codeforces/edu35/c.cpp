#include <iostream>

using namespace std;

int main() {
    int k1, k2, k3;
    bool found = false;
    cin >> k1 >> k2 >> k3;

    if (k1 == 1 || k2 == 1 || k3 == 1) {
        found = true;
    }

    if (k1 == k2 && k2 == k3 && k3 == 3) {
        found = true;
    }

    if (k1 == k2 && k2 == 2 || k2 == k3 && k3 == 2 || k1 == k3 && k3 == 2) {
        found = true;
    }

    if (k1 == k2 && k2 == 4 && k3 == 2 || k1 == k3 && k3 == 4 && k2 == 2 || k2 == k3 && k3 == 4 && k1 == 2) {
        found = true;
    }

    if (!found) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
    }
    return 0;
}