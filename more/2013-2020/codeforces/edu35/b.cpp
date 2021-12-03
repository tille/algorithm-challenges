#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n, a, b, cant;
    cin >> n >> a >> b;

    cant = a + b;
    int maxi = max(a, b);
    int mini = min(a, b);

    for (int i = maxi; true; --i) {
        int mini_plates = mini / i;
        int maxi_plates = maxi / i;

        if (maxi_plates + mini_plates >= n && mini_plates != 0 && maxi_plates != 0) {
            cout << i << endl;
            break;
        }
    }

    return 0;
}