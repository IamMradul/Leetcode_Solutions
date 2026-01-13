/*
====================================================
Author: Mradul Gupta
GitHub Username: IamMradul
GitHub Profile: https://github.com/IamMradul
LeetCode Username: Mradul_mg
LeetCode Profile: https://leetcode.com/u/Mradul_mg/

LeetCode Problem: 50. Pow(x, n)
Problem Link: https://leetcode.com/problems/powx-n/

Time Complexity: O(log n)
Space Complexity: O(log n)   // due to recursion stack
====================================================
*/

#include <bits/stdc++.h>
using namespace std;

// ==================== LeetCode Solution ====================
class Solution {
public:
    double power(double x, long long n) {
        if (n == 0) return 1.0;

        double res = power(x, n / 2);
        res *= res;

        if (n % 2 == 1)
            res *= x;

        return res;
    }

    double myPow(double x, int n) {
        long long N = n;

        // Handle negative exponent
        if (N < 0) {
            x = 1 / x;
            N = -N;
        }

        return power(x, N);
    }
};

// ==================== Local Testing ====================
int main() {
    Solution sol;

    vector<pair<double, int>> testCases = {
        {2.0, 10},
        {2.1, 3},
        {2.0, -2},
        {5.0, 0},
        {1.5, -3}
    };

    for (auto &tc : testCases) {
        cout << "x = " << tc.first << ", n = " << tc.second
             << " -> Result = " << sol.myPow(tc.first, tc.second) << endl;
    }

    return 0;
}
