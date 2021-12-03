#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long
#define vi vector<int>
 
int main() {
    int n, a, b;
    cin >> n >> a >> b;

    cout << (n - max(a+1, n-b) + 1) << endl;
    return 0;
}