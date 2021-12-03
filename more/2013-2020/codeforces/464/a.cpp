#include <iostream>

using namespace std;

const int MAXN = 5002;

int main() {
    int n;
    bool found = false;
    int arr[MAXN];

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
    }

    for (int i = 1; i <= n; ++i) {
        int b = arr[i];
        int c = arr[b];
        if (arr[c] == i) {
            found = true;
            break;
        }
    }

    cout << (found ? "YES" : "NO") << endl;
    return 0;
}