// Author: Mradul Gupta
// GitHub: https://github.com/IamMradul
// Problem: <Problem Name> (LeetCode <Problem Number>)
// Link: <LeetCode Problem URL>

// ---------------------------
// ✅ LeetCode Solution Starts Here
// ---------------------------
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& a) {
        sort(a.begin(), a.end());
        vector<vector<int>> ans;
        int n = a.size();
        
        for (int i = 0; i < n - 2; i++) {
            if (i > 0 && a[i] == a[i - 1]) continue; // Skip duplicate elements for i
            int l = i + 1, r = n - 1;
            while (l < r) {
                long s = (long)a[i] + a[l] + a[r];
                if (s == 0) {
                    ans.push_back({a[i], a[l], a[r]});
                    while (l < r && a[l] == a[l + 1]) l++; // Skip duplicates for l
                    while (l < r && a[r] == a[r - 1]) r--; // Skip duplicates for r
                    l++; r--;
                } else if (s < 0) {
                    l++;
                } else {
                    r--;
                }
            }
        }
        return ans;
    }
};
// ---------------------------
// ✅ LeetCode Solution Ends Here
// ---------------------------

// Example usage (for testing locally):
// int main() {
//     Solution sol;
//     vector<int> nums = {-1, 0, 1, 2, -1, -4};
//     vector<vector<int>> result = sol.threeSum(nums);
//     for (auto& triplet : result) {
//         for (int num : triplet) cout << num << " ";
//         cout << endl;
//     }
//     return 0;
// }
