#include <set>
#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

#define ll long long
#define vi vector<int>

int main() {
    int n, x;
    cin >> n >> x;
    x--;

    vi nums(n);
    set<int> seen;
    for (int i = 0; i < n; ++i) {
        int num; cin >> num;
        nums[i] = num-1;
    }

    while (!seen.count(x)) {
        seen.insert(x);
        x = nums[x];
    }

    cout << seen.size() << endl;
    
    return 0;
}