/*
 * Author: Mradul Gupta
 * GitHub Username: IamMradul
 *
 * LeetCode Problem: 8. String to Integer (atoi)
 * Link: https://leetcode.com/problems/string-to-integer-atoi/
 *
 * Problem Description:
 * Implement the `atoi` function which converts a string to a 32-bit signed integer.
 * The function discards leading whitespace, handles an optional '+' or '-' sign,
 * and reads digits until a non-digit character is encountered. Overflow is clamped 
 * to INT_MAX or INT_MIN.
 *
 * Approach:
 * - Skip leading whitespaces.
 * - Check for optional '+' or '-' sign.
 * - Traverse digits and build the number, checking for overflow.
 * - Return the number multiplied by the sign.
 *
 * Time Complexity: O(n), where n = length of string s
 * Space Complexity: O(1)
 */

 #include <bits/stdc++.h>
 using namespace std;
 
 // ---------------- LeetCode Solution ----------------
 class Solution {
 public:
     int myAtoi(string s) {
         int res = 0;
         int sign = 1;
         int i = 0;
 
         while (i < s.size() && s[i] == ' ') i++;
 
         if (i < s.size() && (s[i] == '-' || s[i] == '+')) {
             if (s[i] == '-') sign = -1;
             i++;
         }
 
         while (i < s.size() && s[i] >= '0' && s[i] <= '9') {
             int a = s[i] - '0';
             if (res > (INT_MAX - a) / 10) {
                 return (sign == 1) ? INT_MAX : INT_MIN;
             }
             res = res * 10 + a;
             i++;
         }
 
         return res * sign;
     }
 };
 // ---------------------------------------------------
 
 // Example usage with test cases
 int main() {
     Solution sol;
 
     string s1 = "42";
     string s2 = "   -42";
     string s3 = "4193 with words";
     string s4 = "-91283472332";
 
     cout << "Input: \"" << s1 << "\" → Output: " << sol.myAtoi(s1) << endl;
     cout << "Input: \"" << s2 << "\" → Output: " << sol.myAtoi(s2) << endl;
     cout << "Input: \"" << s3 << "\" → Output: " << sol.myAtoi(s3) << endl;
     cout << "Input: \"" << s4 << "\" → Output: " << sol.myAtoi(s4) << endl;
 
     return 0;
 }
 