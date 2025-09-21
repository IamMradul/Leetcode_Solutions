//IamMradul
// File: find_peak_element.cpp
// Author: Mradul Gupta
// Description: C++ solution for finding a peak element in an array using binary search.

// --------------------- LeetCode Solution Starts Here ---------------------
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size(); 
        if (n == 1) return 0;
        if (nums[0] > nums[1]) return 0;
        if (nums[n - 1] > nums[n - 2]) return n - 1;

        int low = 1, high = n - 2;
        while (low <= high) {
            int mid = (low + high) / 2;

            if (nums[mid - 1] < nums[mid] && nums[mid] > nums[mid + 1])
                return mid;

            if (nums[mid] > nums[mid - 1]) 
                low = mid + 1;
            else 
                high = mid - 1;
        }
        return -1;
    }
};
// --------------------- LeetCode Solution Ends Here ---------------------

// Driver code for testing (Not part of LeetCode submission)
#include <bits/stdc++.h>
using namespace std;

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3, 1};
    int peakIndex = sol.findPeakElement(nums);
    cout << "Peak element index: " << peakIndex << endl;
    cout << "Peak element value: " << nums[peakIndex] << endl;
    return 0;
}
