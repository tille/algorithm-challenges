#include <iostream>

using namespace std;

int main() {
    int n, mini, pos, num, res;
    mini = 1 << 30;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> num;
        if (num < mini) {
            pos = i;
            mini = num;
            res = 1 << 30;
        } else if (num == mini) {
            res = min(res, i - pos);
            pos = i;
        }
    }
    cout << res << endl;
    return 0;
}