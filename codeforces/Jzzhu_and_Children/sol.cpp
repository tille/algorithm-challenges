#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>

int main() {
    int n, m, right = 0, num;
    cin >> n >> m;
    vi arr(n);

    for (int i = 0; i < n; ++i) {
        cin >> num;
        arr[i] = ceil(num / double(m));
    }
    
    for (int i = 0; i < n; ++i) if (arr[i] >= arr[right]) right = i;
    cout << right+1 << endl;
    return 0;
}