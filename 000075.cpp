/*
 * Author: Mradul Gupta
 * GitHub Username: IamMradul
 *
 * LeetCode Problem: 75. Sort Colors
 * Link: https://leetcode.com/problems/sort-colors/
 *
 * Problem Description:
 * Given an array `nums` with n objects colored red, white, or blue (represented as 0, 1, and 2),
 * sort them in-place so that objects of the same color are adjacent, with the colors in order:
 * red (0), white (1), and blue (2).
 *
 * You must solve this problem without using the built-in sort function.
 *
 * Approach (Dutch National Flag Algorithm):
 * - Maintain three pointers: low, mid, and high.
 * - Traverse the array with `mid`:
 *      - If nums[mid] == 0 → swap with nums[low], increment both low and mid.
 *      - If nums[mid] == 1 → just increment mid.
 *      - If nums[mid] == 2 → swap with nums[high], decrement high.
 * - Continue until mid > high.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1) (in-place sorting)
 */

 #include <bits/stdc++.h>
 using namespace std;
 
 // ---------------- LeetCode Solution ----------------
 class Solution {
 public:
     void sortColors(vector<int>& nums) {
         int low = 0;
         int high = nums.size() - 1;
         int mid = 0;
 
         while (mid <= high) {
             if (nums[mid] == 0) {
                 swap(nums[low], nums[mid]);
                 mid++;
                 low++;
             }
             else if (nums[mid] == 1) {
                 mid++;
             }
             else {
                 swap(nums[mid], nums[high]);
                 high--;
             }
         }
     }
 };
 // ---------------------------------------------------
 
 // Example usage with test case
 int main() {
     Solution sol;
     vector<int> nums = {2, 0, 2, 1, 1, 0};
 
     cout << "Original array: ";
     for (int x : nums) cout << x << " ";
     cout << endl;
 
     sol.sortColors(nums);
 
     cout << "Sorted array:   ";
     for (int x : nums) cout << x << " ";
     cout << endl;
 
     return 0;
 }
 