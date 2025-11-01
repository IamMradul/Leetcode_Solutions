/*
 * Author: Mradul Gupta
 * GitHub Username: IamMradul
 *
 * LeetCode Problem: 1. Two Sum
 * Link: https://leetcode.com/problems/two-sum/
 *
 * Problem Description:
 * Given an array of integers `nums` and an integer `target`, return indices of 
 * the two numbers such that they add up to `target`.
 * 
 * You may assume that each input would have exactly one solution, and you may 
 * not use the same element twice. You can return the answer in any order.
 *
 * Approach:
 * - Use a hash map (unordered_map or map) to store previously visited numbers and their indices.
 * - For each number, compute `rem = target - nums[i]`.
 * - If `rem` exists in the map, return indices {i, mpp[rem]}.
 * - Otherwise, store nums[i] in the map with its index.
 *
 * Time Complexity: O(n), where n = size of nums
 * Space Complexity: O(n)
 */

 #include <bits/stdc++.h>
 using namespace std;
 
 // ---------------- LeetCode Solution ----------------
 class Solution {
 public:
     vector<int> twoSum(vector<int>& nums, int target) {
         int n = nums.size();
         map<int,int> mpp; // number -> index
 
         for (int i = 0; i < n; i++) {
             int rem = target - nums[i];
             if (mpp.find(rem) != mpp.end()) {
                 return {i, mpp[rem]};
             }
             mpp[nums[i]] = i;
         }
         return {-1, -1}; // Not expected as per problem guarantee
     }
 };
 // ---------------------------------------------------
 
 // Example usage with test case
 int main() {
     Solution sol;
     vector<int> nums = {2, 7, 11, 15};
     int target = 9;
 
     vector<int> result = sol.twoSum(nums, target);
     cout << "Indices: [" << result[0] << ", " << result[1] << "]" << endl;
 
     return 0;
 }
 