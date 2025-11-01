/*
 * Author: Mradul Gupta
 * GitHub Username: IamMradul
 *
 * LeetCode Problem: 13. Roman to Integer
 * Link: https://leetcode.com/problems/roman-to-integer/
 *
 * Problem Description:
 * Given a roman numeral, convert it to an integer.
 * Roman numerals are represented by seven symbols: I, V, X, L, C, D, and M.
 * Special cases occur when a smaller numeral appears before a larger numeral,
 * in which case the smaller numeral is subtracted (e.g., IV = 4, IX = 9).
 *
 * Approach:
 * - Use an unordered_map to store the integer values of Roman characters.
 * - Traverse the string from left to right, comparing each character with the next one.
 * - If the current value is less than the next one, subtract it (subtractive notation).
 * - Otherwise, add it normally.
 * - Finally, add the last character's value to the result.
 *
 * Time Complexity: O(n), where n = length of s
 * Space Complexity: O(1), since we only use a fixed map of 7 Roman numerals
 */

 #include <bits/stdc++.h>
 using namespace std;
 
 // ---------------- LeetCode Solution ----------------
 class Solution {
 public:
     int romanToInt(string s) {
         int res = 0;
         unordered_map<char,int> mpp = {
             {'I', 1}, {'V', 5}, {'X', 10},
             {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}
         };
 
         for (int i = 0; i < s.size() - 1; i++) {
             if (mpp[s[i]] < mpp[s[i + 1]]) {
                 res -= mpp[s[i]];
             } else {
                 res += mpp[s[i]];
             }
         }
         res += mpp[s.back()];
         return res;
     }
 };
 // ---------------------------------------------------
 
 // Example usage with test case
 int main() {
     Solution sol;
 
     string s1 = "III";
     string s2 = "LVIII";
     string s3 = "MCMXCIV";
 
     cout << "Input: " << s1 << " → Integer: " << sol.romanToInt(s1) << endl;
     cout << "Input: " << s2 << " → Integer: " << sol.romanToInt(s2) << endl;
     cout << "Input: " << s3 << " → Integer: " << sol.romanToInt(s3) << endl;
 
     return 0;
 }
 