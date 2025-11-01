/*
 * Author: Mradul Gupta
 * GitHub Username: IamMradul
 *
 * LeetCode Problem: 1903. Largest Odd Number in String
 * Link: https://leetcode.com/problems/largest-odd-number-in-string/
 *
 * Problem Description:
 * You are given a string `num`, representing a large integer.
 * Return the largest-valued odd integer (as a string) that is a non-empty 
 * substring of `num`, or return an empty string if no odd integer exists.
 *
 * Approach:
 * - Traverse from the last digit towards the start.
 * - The first odd digit encountered determines the largest odd number 
 *   because everything before it can be included.
 * - Return substring from start to that index.
 * - If no odd digit exists, return "".
 *
 * Time Complexity: O(n), where n = length of num
 * Space Complexity: O(1)
 */

 #include <bits/stdc++.h>
 using namespace std;
 
 // ---------------- LeetCode Solution ----------------
 class Solution {
 public:
     string largestOddNumber(string num) {
         for (int i = num.size() - 1; i >= 0; i--) {
             if ((num[i] - '0') % 2 != 0) {  
                 return num.substr(0, i + 1);
             }
         }
         return ""; 
     }
 };
 // ---------------------------------------------------
 
 // Example usage with test case
 int main() {
     Solution sol;
     string num1 = "35420";
     string num2 = "42068";
 
     cout << "Input: " << num1 << " → Largest odd number: " 
          << sol.largestOddNumber(num1) << endl;
 
     cout << "Input: " << num2 << " → Largest odd number: " 
          << sol.largestOddNumber(num2) << endl;
 
     return 0;
 }
 