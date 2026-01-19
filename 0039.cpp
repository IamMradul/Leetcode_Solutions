/*
====================================================
Author: Mradul Gupta
GitHub Username: IamMradul
GitHub Profile: https://github.com/IamMradul
LeetCode Username: Mradul_mg
LeetCode Profile: https://leetcode.com/u/Mradul_mg/

LeetCode Problem: 39. Combination Sum
Problem Link: https://leetcode.com/problems/combination-sum/

Time Complexity: O(2^t)   // t = target (worst-case exponential backtracking)
Space Complexity: O(t)    // recursion stack + current combination
====================================================
*/

#include <bits/stdc++.h>
using namespace std;

// ==================== LeetCode Solution ====================
class Solution {
public:
    void findCombination(int ind, int target,
                         vector<int>& arr,
                         vector<vector<int>>& ans,
                         vector<int>& ds) {
        // If we have considered all elements
        if (ind == arr.size()) {
            if (target == 0) {
                ans.push_back(ds);
            }
            return;
        }

        // Pick the current element (can be reused)
        if (arr[ind] <= target) {
            ds.push_back(arr[ind]);
            findCombination(ind, target - arr[ind], arr, ans, ds);
            ds.pop_back(); // backtrack
        }

        // Move to the next element
        findCombination(ind + 1, target, arr, ans, ds);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        findCombination(0, target, candidates, ans, ds);
        return ans;
    }
};

// ==================== Local Testing ====================
int main() {
    Solution sol;

    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;

    vector<vector<int>> result = sol.combinationSum(candidates, target);

    cout << "Combinations that sum to " << target << ":\n";
    for (const auto &comb : result) {
        cout << "[ ";
        for (int x : comb) {
            cout << x << " ";
        }
        cout << "]\n";
    }

    return 0;
}
