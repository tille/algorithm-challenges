#include <iostream>

using namespace std;

int main() {
    int cases, chucks;
    cin >> cases;

    while (cases--) {
        cin >> chucks;
        int cant = int(chucks / 7), cant;
        bool found = false;

        for (int i = 0; i <= cant; ++i) {
            rest = chucks - (7 * i);
            if (rest % 3 == 0) {
                found = true;
                break;
            }
        }

        if (found) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}