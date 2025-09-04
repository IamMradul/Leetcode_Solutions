//IamMradul
#include <bits/stdc++.h>
using namespace std;

/*
    -----------------------------
    ✅ LEETCODE SUBMISSION PART ✅
    -----------------------------
    Just copy this class and its function for LeetCode submission.
*/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target) {
                return mid; // Found target
            }

            // Left half is sorted
            if (nums[low] <= nums[mid]) {
                if (nums[low] <= target && target < nums[mid]) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
            // Right half is sorted
            else {
                if (nums[mid] < target && target <= nums[high]) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }

        return -1; // Target not found
    }
};

/*
    -----------------------------
    ✅ LOCAL TESTING PART ✅
    -----------------------------
    This part is for your GitHub and local testing. 
    DO NOT include this part when submitting to LeetCode.
*/
int main() {
    Solution sol;

    // Example 1
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int target = 0;

    int result = sol.search(nums, target);
    cout << "Index of " << target << ": " << result << endl;

    // Example 2
    nums = {4,5,6,7,0,1,2};
    target = 3;
    cout << "Index of " << target << ": " << sol.search(nums, target) << endl;

    // Example 3
    nums = {1};
    target = 0;
    cout << "Index of " << target << ": " << sol.search(nums, target) << endl;

    return 0;
}
