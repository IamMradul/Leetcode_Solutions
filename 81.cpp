//IamMradul
/*
    Problem: Search in Rotated Sorted Array II (with duplicates)
    LeetCode: https://leetcode.com/problems/search-in-rotated-sorted-array-ii/

    ✅ Approach:
    - Modified Binary Search
    - Handles duplicates by shrinking the search space when ambiguity occurs
    - Time Complexity: O(log n) average, O(n) worst case (due to duplicates)
    - Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

// -------------------------
// ✅ LeetCode Solution Starts Here
// -------------------------
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target) {
                return true;
            }

            // Handle duplicates: shrink the window
            if (nums[mid] == nums[low] && nums[mid] == nums[high]) {
                low++;
                high--;
                continue; // Skip further checks in this iteration
            }

            // If left half is sorted
            if (nums[low] <= nums[mid]) {
                if (nums[low] <= target && target < nums[mid]) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
            // Else, right half is sorted
            else {
                if (nums[mid] < target && target <= nums[high]) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }
        return false;
    }
};
// -------------------------
// ✅ LeetCode Solution Ends Here
// -------------------------

// ✅ Local Testing Main Function
int main() {
    Solution sol;

    // Test case 1
    vector<int> nums1 = {2,5,6,0,0,1,2};
    int target1 = 0;
    cout << "Test 1: " << (sol.search(nums1, target1) ? "Found" : "Not Found") << endl;

    // Test case 2
    vector<int> nums2 = {2,5,6,0,0,1,2};
    int target2 = 3;
    cout << "Test 2: " << (sol.search(nums2, target2) ? "Found" : "Not Found") << endl;

    // Test case 3 (with duplicates)
    vector<int> nums3 = {1,1,1,1,2,1,1};
    int target3 = 2;
    cout << "Test 3: " << (sol.search(nums3, target3) ? "Found" : "Not Found") << endl;

    return 0;
}

/*
    ✅ Expected Output:
    Test 1: Found
    Test 2: Not Found
    Test 3: Found
*/
