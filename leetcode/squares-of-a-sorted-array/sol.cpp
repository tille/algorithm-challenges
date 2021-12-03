#include <bits/stdc++.h>

using namespace std;

int cpow(int a) {
    return a*a;
}



vector<int> sortedSquares(vector<int>& nums) {
    int p1 = 0, p2 = nums.size()-1;
    vector<int> ans;
    while (p1 <= p2) {
        int a = cpow(nums[p1]);
        int b = cpow(nums[p2]);

        if (a < b) {
            ans.push_back(b);
            p2--;
        } else {
            ans.push_back(a);
            p1++;
        }
    }
    reverse(ans.begin(), ans.end());
    nums = ans; 
    return nums;
}

int main() {
    vector<int> t = {-4,-1,0,3,10};
    sortedSquares(t);

    for (auto &x: t) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}