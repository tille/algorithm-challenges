#include <bits/stdc++.h>

using namespace std;
#define vi vector<int>

int partition(int l, int r, vi &arr) {
    int pivot = arr[r];
    int index = l;

    for (int j = l; j < r; ++j) {
        if (arr[j] < pivot) {
            swap(arr[j], arr[index]);
            index++;
        }
    }
    swap(arr[r], arr[index]);
    return index;
}

int randomPivotPartition(int low, int high, vi &arr) {
	int n = rand();
	int pvt = low + n%(high-low+1);
	swap(arr[high], arr[pvt]);
	return partition(low, high, arr);
}

void quickSort(int l, int r, vi &arr) {
    if (l < r) {
        int pivot = randomPivotPartition(l, r, arr);
        if (l < pivot - 1) quickSort(l, pivot - 1, arr);
        if (pivot + 1 < r) quickSort(pivot + 1, r, arr);
    }
}

int main() {
    int n; cin >> n;
    vi arr(n);

    for (auto &num : arr) cin >> num;
    quickSort(0, n-1, arr);

    for (auto x : arr) cout << x << " ";
    cout << endl;
    return 0;
}