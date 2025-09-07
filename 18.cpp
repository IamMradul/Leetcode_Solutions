// Author: Mradul Gupta
// GitHub Username: IamMradul
// Problem: LeetCode - 4Sum
// --------------------------------------------

// ✅ LeetCode Solution Starts Here
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size(); 
        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue; // Skip duplicate for i

            for (int j = i + 1; j < n; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue; // Skip duplicate for j

                int k = j + 1;
                int l = n - 1;
                
                while (k < l) {
                    long long sum = (long long)nums[i] + nums[j] + nums[k] + nums[l];
                    
                    if (sum == target) {
                        ans.push_back({nums[i], nums[j], nums[k], nums[l]});
                        k++; 
                        l--;

                        while (k < l && nums[k] == nums[k - 1]) k++; // Skip duplicates for k
                        while (k < l && nums[l] == nums[l + 1]) l--; // Skip duplicates for l
                    }
                    else if (sum < target) {
                        k++;
                    } 
                    else {
                        l--;
                    }
                }
            }
        }
        return ans;
    }
};
// ✅ LeetCode Solution Ends Here

// ✅ Main function for testing
int main() {
    Solution obj;
    vector<int> nums = {1, 0, -1, 0, -2, 2};
    int target = 0;

    vector<vector<int>> result = obj.fourSum(nums, target);

    cout << "Quadruplets that sum to " << target << " are:\n";
    for (auto &quad : result) {
        cout << "[ ";
        for (auto &num : quad) {
            cout << num << " ";
        }
        cout << "]\n";
    }

    return 0;
}
