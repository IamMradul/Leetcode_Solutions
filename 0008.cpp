/*
====================================================
Author: Mradul Gupta
GitHub Username: IamMradul
GitHub Profile: https://github.com/IamMradul
LeetCode Username: Mradul_mg
LeetCode Profile: https://leetcode.com/u/Mradul_mg/

LeetCode Problem: 8. String to Integer (atoi)
Problem Link: https://leetcode.com/problems/string-to-integer-atoi/

Time Complexity: O(n)
Space Complexity: O(1)
====================================================
*/

#include <bits/stdc++.h>
using namespace std;

// ==================== LeetCode Solution ====================
class Solution {
public:
    int myAtoi(string s) {
        int i = 0, n = s.size();
        long long result = 0;
        int sign = 1;

        // Skip leading spaces
        while (i < n && s[i] == ' ') {
            i++;
        }

        // Handle sign
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            if (s[i] == '-') sign = -1;
            i++;
        }

        // Convert digits
        while (i < n && isdigit(s[i])) {
            result = result * 10 + (s[i] - '0');

            // Handle overflow
            if (sign * result >= INT_MAX)
                return INT_MAX;
            if (sign * result <= INT_MIN)
                return INT_MIN;

            i++;
        }

        return sign * result;
    }
};

// ==================== Local Testing ====================
int main() {
    Solution sol;

    vector<string> testCases = {
        "42",
        "   -42",
        "4193 with words",
        "words and 987",
        "-91283472332"
    };

    for (const string& s : testCases) {
        cout << "Input: \"" << s << "\" -> Output: "
             << sol.myAtoi(s) << endl;
    }

    return 0;
}
