#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, leaves, newPassengers, passengers = 0, maxPassengers = 0;
    cin >> n;

    while (n--) {
        cin >> leaves >> newPassengers;
        passengers = passengers - leaves + newPassengers;
        maxPassengers = max(maxPassengers, passengers);
    }
    cout << maxPassengers << endl;
    return 0;
}