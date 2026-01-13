/*
====================================================
Author: Mradul Gupta
GitHub Username: IamMradul
GitHub Profile: https://github.com/IamMradul
LeetCode Username: Mradul_mg
LeetCode Profile: https://leetcode.com/u/Mradul_mg/

LeetCode Problem: 22. Generate Parentheses
Problem Link: https://leetcode.com/problems/generate-parentheses/

Time Complexity: O(4^n / sqrt(n))   // Catalan number growth
Space Complexity: O(n)              // recursion stack (excluding output)
====================================================
*/

#include <bits/stdc++.h>
using namespace std;

// ==================== LeetCode Solution ====================
class Solution {
public:
    vector<string> res;

    void solve(string s, int open, int close, int n) {
        // If the current string is of required length
        if (s.length() == 2 * n) {
            res.push_back(s);
            return;
        }

        // Add '(' if we still have open brackets left
        if (open < n) {
            solve(s + '(', open + 1, close, n);
        }

        // Add ')' only if it does not invalidate the sequence
        if (close < open) {
            solve(s + ')', open, close + 1, n);
        }
    }

    vector<string> generateParenthesis(int n) {
        solve("", 0, 0, n);
        return res;
    }
};

// ==================== Local Testing ====================
int main() {
    Solution sol;

    int n = 3;
    vector<string> ans = sol.generateParenthesis(n);

    cout << "Generated Parentheses for n = " << n << ":\n";
    for (const string &s : ans) {
        cout << s << endl;
    }

    return 0;
}
