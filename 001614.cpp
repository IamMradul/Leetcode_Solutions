/*
 * Author: Mradul Gupta
 * GitHub Username: IamMradul
 *
 * LeetCode Problem: 1614. Maximum Nesting Depth of the Parentheses
 * Link: https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/
 *
 * Problem Description:
 * A string is a valid parentheses string (VPS) if it consists of '(' and ')' characters and is properly nested.
 * The nesting depth of a VPS is the maximum number of nested parentheses at any position.
 * Given a valid parentheses string `s`, return its maximum nesting depth.
 *
 * Approach:
 * - Use a counter `cnt` to track the current depth while traversing the string.
 * - Increment `cnt` when '(' is encountered and decrement when ')' is encountered.
 * - Keep track of the maximum depth encountered using `res`.
 *
 * Time Complexity: O(n), where n = length of s
 * Space Complexity: O(1)
 */

 #include <bits/stdc++.h>
 using namespace std;
 
 // ---------------- LeetCode Solution ----------------
 class Solution {
 public:
     int maxDepth(string s) {
         int cnt = 0, res = 0;
         for (int i = 0; i < s.size(); i++) {
             if (s[i] == '(') {
                 cnt++;
             }
             res = max(res, cnt);
             if (s[i] == ')') {
                 cnt--;
             }
         }
         return res;
     }
 };
 // ---------------------------------------------------
 
 // Example usage with test case
 int main() {
     Solution sol;
     string s1 = "(1+(2*3)+((8)/4))+1";
     string s2 = "(1)+((2))+(((3)))";
 
     cout << "Input: " << s1 << " → Max Nesting Depth: " << sol.maxDepth(s1) << endl;
     cout << "Input: " << s2 << " → Max Nesting Depth: " << sol.maxDepth(s2) << endl;
 
     return 0;
 }
 