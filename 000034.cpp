//IamMradul
#include <bits/stdc++.h>
using namespace std;

// ======================
// ✅ LeetCode Solution
// ======================
class Solution {
public:
    // Function to find the first occurrence of target
    int findFirst(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        int first = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target) {
                first = mid;
                high = mid - 1; // go left for first occurrence
            } else if (nums[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return first;
    }

    // Function to find the last occurrence of target
    int findLast(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        int last = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target) {
                last = mid;
                low = mid + 1; // go right for last occurrence
            } else if (nums[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return last;
    }

    // Main function that returns the first and last position
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = findFirst(nums, target);
        int last = findLast(nums, target);
        return {first, last};
    }
};

// ======================
// ✅ Main function for local testing
// ======================
int main() {
    Solution sol;

    // Sample test case
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    int target = 8;

    vector<int> result = sol.searchRange(nums, target);

    cout << "First and Last Position of " << target << ": ["
         << result[0] << ", " << result[1] << "]" << endl;

    return 0;
}
