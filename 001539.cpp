// Problem: 1539. Kth Missing Positive Number
// Link: https://leetcode.com/problems/kth-missing-positive-number/
//
// Author: Mradul Gupta
// GitHub: https://github.com/IamMradul

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int low = 0;
        int high = arr.size() - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            int missing = arr[mid] - (mid + 1);

            if (k > missing) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return low + k;
    }
};

// ---------- Local Test Driver ----------
int main() {
    Solution sol;

    vector<int> arr1 = {2, 3, 4, 7, 11};
    int k1 = 5;
    cout << "Test 1 -> " << sol.findKthPositive(arr1, k1) << endl; // Expected: 9

    vector<int> arr2 = {1, 2, 3, 4};
    int k2 = 2;
    cout << "Test 2 -> " << sol.findKthPositive(arr2, k2) << endl; // Expected: 6

    vector<int> arr3 = {5, 6, 7, 8};
    int k3 = 3;
    cout << "Test 3 -> " << sol.findKthPositive(arr3, k3) << endl; // Expected: 3

    return 0;
}
