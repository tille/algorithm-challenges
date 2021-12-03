#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, a, b;
    
    cin >> n;
    vector<int> left(2, 0), right(2, 0);

    while (n--) {
        cin >> a >> b;
        left[a]++;
        right[b]++;
    }

    cout << (min(left[0], left[1]) + min(right[0], right[1])) << endl;
    return 0;
}