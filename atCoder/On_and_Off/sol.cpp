#include <iostream>
#include <stdio.h>

using namespace std;

#define ll long long
#define vi vector<int>

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    c = (c+1 == 24) ? 0 : c+1;
    if (b > a) {
        cout << (c > a && c <= b ? "Yes" : "No") << endl;
    } else {
        cout << (c > a or c <= b ? "Yes" : "No") << endl;
    }
    return 0;
}