//IamMradul
/*
====================================
    🔹 Find Minimum in Rotated Sorted Array
    🔹 Problem Link: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
    🔹 Difficulty: Medium
    🔹 Language: C++
====================================
*/

#include <bits/stdc++.h>
using namespace std;

// =================== LEETCODE SOLUTION START ===================
class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;
        int ans = INT_MAX;

        while (low <= high) {
            int mid = (low + high) / 2;

            // If array is already sorted in this range
            if (nums[low] <= nums[high]) {
                ans = min(ans, nums[low]);
                break;
            }

            // Left part is sorted
            if (nums[low] <= nums[mid]) {
                ans = min(ans, nums[low]);
                low = mid + 1;
            }
            // Right part is sorted
            else {
                ans = min(ans, nums[mid]);
                high = mid - 1;
            }
        }
        return ans;
    }
};
// =================== LEETCODE SOLUTION END ===================

// =================== SAMPLE TEST (For Local Execution) ===================
int main() {
    Solution sol;
    vector<int> nums = {4,5,6,7,0,1,2};
    cout << "Minimum element: " << sol.findMin(nums) << endl;
    return 0;
}
