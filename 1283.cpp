// Author: Mradul Gupta
// GitHub: https://github.com/IamMradul
// Problem: LeetCode - Smallest Divisor Given a Threshold
// Difficulty: Medium

#include <bits/stdc++.h>
using namespace std;

// -------------------- LeetCode Solution Starts --------------------
class Solution {
public:
    int sumByD(vector<int> &arr, int div) {
        int n = arr.size(); 
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += ceil((double)(arr[i]) / (double)(div));
        }
        return sum;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();
        if (n > threshold) return -1;
        
        int low = 1, high = *max_element(nums.begin(), nums.end());
        while (low <= high) {
            int mid = (low + high) / 2;
            if (sumByD(nums, mid) <= threshold) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};
// -------------------- LeetCode Solution Ends --------------------

// Example main function (for local testing only)
int main() {
    Solution sol;
    vector<int> nums = {1, 2, 5, 9};
    int threshold = 6;
    cout << sol.smallestDivisor(nums, threshold) << endl; // Output: 5
    return 0;
}
