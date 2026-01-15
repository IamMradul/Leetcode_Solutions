/*
====================================================
Author: Mradul Gupta
GitHub Username: IamMradul
GitHub Profile: https://github.com/IamMradul
LeetCode Username: Mradul_mg
LeetCode Profile: https://leetcode.com/u/Mradul_mg/

LeetCode Problem: 78. Subsets
Problem Link: https://leetcode.com/problems/subsets/

Time Complexity: O(n * 2^n)
Space Complexity: O(n * 2^n)   // storing all subsets
====================================================
*/

#include <bits/stdc++.h>
using namespace std;

// ==================== LeetCode Solution ====================
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        int n = nums.size();
        int total = 1 << n;  // total subsets = 2^n

        for (int mask = 0; mask < total; mask++) {
            vector<int> subset;
            for (int j = 0; j < n; j++) {
                if (mask & (1 << j)) {
                    subset.push_back(nums[j]);
                }
            }
            res.push_back(subset);
        }
        return res;
    }
};

// ==================== Local Testing ====================
int main() {
    Solution sol;

    vector<int> nums = {1, 2, 3};
    vector<vector<int>> ans = sol.subsets(nums);

    cout << "Subsets:\n";
    for (const auto &subset : ans) {
        cout << "[ ";
        for (int x : subset) {
            cout << x << " ";
        }
        cout << "]\n";
    }

    return 0;
}
