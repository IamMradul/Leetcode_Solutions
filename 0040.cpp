/*
====================================================
Author: Mradul Gupta
GitHub Username: IamMradul
GitHub Profile: https://github.com/IamMradul
LeetCode Username: Mradul_mg
LeetCode Profile: https://leetcode.com/u/Mradul_mg/

LeetCode Problem: 40. Combination Sum II
Problem Link: https://leetcode.com/problems/combination-sum-ii/

Time Complexity: O(2^n)     // backtracking over subsets
Space Complexity: O(n)      // recursion stack + current combination
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

        // If target becomes zero, store the valid combination
        if (target == 0) {
            ans.push_back(ds);
            return;
        }

        for (int i = ind; i < arr.size(); i++) {
            // Skip duplicates at the same recursion level
            if (i > ind && arr[i] == arr[i - 1]) continue;

            // No need to proceed further if current value exceeds target
            if (arr[i] > target) break;

            ds.push_back(arr[i]);
            findCombination(i + 1, target - arr[i], arr, ans, ds);
            ds.pop_back(); // backtrack
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end()); // required for duplicate handling
        vector<vector<int>> ans;
        vector<int> ds;

        findCombination(0, target, candidates, ans, ds);
        return ans;
    }
};

// ==================== Local Testing ====================
int main() {
    Solution sol;

    vector<int> candidates = {10, 1, 2, 7, 6, 1, 5};
    int target = 8;

    vector<vector<int>> result = sol.combinationSum2(candidates, target);

    cout << "Unique combinations that sum to " << target << ":\n";
    for (const auto &comb : result) {
        cout << "[ ";
        for (int x : comb) {
            cout << x << " ";
        }
        cout << "]\n";
    }

    return 0;
}
