/*
    Author: Mradul Gupta
    GitHub: https://github.com/IamMradul
*/

// ------------------ LEETCODE SOLUTION START ------------------
class Solution {
    public:
        vector<vector<int>> merge(vector<vector<int>>& intervals) {
            sort(intervals.begin(), intervals.end());
            
            vector<vector<int>> merged;
            
            for (auto &interval : intervals) {
                if (merged.empty() || merged.back()[1] < interval[0]) {
                    merged.push_back(interval);
                } else {
                    merged.back()[1] = max(merged.back()[1], interval[1]);
                }
            }
            
            return merged;
        }
    };
    // ------------------ LEETCODE SOLUTION END ------------------
    
    #include <bits/stdc++.h>
    using namespace std;
    
    int main() {
        Solution sol;
        vector<vector<int>> intervals = {{1,3},{2,6},{8,10},{15,18}};
        
        vector<vector<int>> result = sol.merge(intervals);
        
        cout << "Merged Intervals: ";
        for (auto &vec : result) {
            cout << "[" << vec[0] << "," << vec[1] << "] ";
        }
        cout << endl;
        
        return 0;
    }
    