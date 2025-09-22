/*
 * Author: Mradul Gupta
 * GitHub Username: IamMradul
 *
 * LeetCode Problem: 1021. Remove Outermost Parentheses
 * Link: https://leetcode.com/problems/remove-outermost-parentheses/
 *
 * Problem Description:
 * A valid parentheses string is either empty "", "(" + A + ")", or A + B, 
 * where A and B are valid parentheses strings.  
 * 
 * A primitive valid parentheses string is a non-empty string that cannot 
 * be split into two non-empty valid parentheses strings.  
 * 
 * Given a valid parentheses string `s`, remove the outermost parentheses of 
 * every primitive string in the primitive decomposition of `s`.
 *
 * Approach:
 * - Use a balance counter `bal` to track nested parentheses.
 * - Traverse the string:
 *      - If '(', append to result only if balance > 0, then increment balance.
 *      - If ')', decrement balance first, then append to result only if balance > 0.
 *
 * Time Complexity: O(n), where n = length of s
 * Space Complexity: O(n) for the result string
 */

 #include <bits/stdc++.h>
 using namespace std;
 
 // ---------------- LeetCode Solution ----------------
 class Solution {
 public:
     string removeOuterParentheses(string s) {
         string result;
         int bal = 0;  
 
         for (char c : s) {
             if (c == '(') {
                 if (bal > 0) result += c;
                 bal++;
             } else { 
                 bal--;
                 if (bal > 0) result += c; 
             }
         }
 
         return result;
     }
 };
 // ---------------------------------------------------
 
 // Example usage with test case
 int main() {
     Solution sol;
     string s = "(()())(())";
 
     cout << "Original string: " << s << endl;
 
     string result = sol.removeOuterParentheses(s);
     cout << "After removing outermost parentheses: " << result << endl;
 
     return 0;
 }
 