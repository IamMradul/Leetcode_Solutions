/*
 * Author: Mradul Gupta
 * GitHub Username: IamMradul
 *
 * LeetCode Problem: 14. Longest Common Prefix
 * Link: https://leetcode.com/problems/longest-common-prefix/
 *
 * Problem Description:
 * Write a function to find the longest common prefix string amongst an array of strings.
 * If there is no common prefix, return an empty string "".
 *
 * Approach:
 * - Sort the array of strings.
 * - The common prefix will be shared between the first and the last string after sorting.
 * - Compare characters of the first and last string until they differ.
 *
 * Time Complexity: O(n * m log n)
 *      - Sorting takes O(n log n * m) where m = average length of string.
 *      - Comparing first and last string takes O(m).
 * Space Complexity: O(1) (ignoring sort’s internal space)
 */

 #include <bits/stdc++.h>
 using namespace std;
 
 // ---------------- LeetCode Solution ----------------
 class Solution {
 public:
     string longestCommonPrefix(vector<string>& strs) {
         if (strs.empty()) return "";
         int n = strs[0].size();
         sort(strs.begin(), strs.end());
         string first = strs[0];
         string last = strs[strs.size() - 1];
         string res = "";
         for (int i = 0; i < n; i++) {
             if (first[i] == last[i]) {
                 res += first[i];
             } else {
                 break;
             }
         }
         return res;
     }
 };
 // ---------------------------------------------------
 
 // Example usage with test case
 int main() {
     Solution sol;
     vector<string> strs1 = {"flower", "flow", "flight"};
     vector<string> strs2 = {"dog", "racecar", "car"};
 
     cout << "Input: [flower, flow, flight] → Longest Common Prefix: " 
          << sol.longestCommonPrefix(strs1) << endl;
 
     cout << "Input: [dog, racecar, car] → Longest Common Prefix: " 
          << sol.longestCommonPrefix(strs2) << endl;
 
     return 0;
 }
 