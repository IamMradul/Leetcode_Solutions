//MG26-spec
#include <bits/stdc++.h>
using namespace std;

// ====== LeetCode Region ======
class Solution {
public:
    vector<int> generateRow(int row) {
        long long ans = 1;
        vector<int> ansRow;
        ansRow.push_back(1);
        for (int col = 1; col < row; col++) {
            ans = ans * (row - col);
            ans = ans / col;
            ansRow.push_back(ans);
        }
        return ansRow;
    }

    vector<vector<int>> generate(int n) {
        vector<vector<int>> ans;
        for (int row = 1; row <= n; row++) {
            ans.push_back(generateRow(row));
        }
        return ans;
    }
};
// ====== End LeetCode Region ======

// ====== Local Test Harness ======
int main() {
    Solution sol;

    int n = 5;  // change this to test different inputs
    vector<vector<int>> result = sol.generate(n);

    // Pretty print Pascal's Triangle
    for (auto &row : result) {
        for (int x : row) cout << x << " ";
        cout << "\n";
    }

    return 0;
}
