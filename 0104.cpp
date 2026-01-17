/*
====================================================
Author: Mradul Gupta
GitHub Username: IamMradul
GitHub Profile: https://github.com/IamMradul
LeetCode Username: Mradul_mg
LeetCode Profile: https://leetcode.com/u/Mradul_mg/

LeetCode Problem: 104. Maximum Depth of Binary Tree
Problem Link: https://leetcode.com/problems/maximum-depth-of-binary-tree/

Time Complexity: O(n)
Space Complexity: O(n)   // recursion stack in worst case
====================================================
*/

#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

// ==================== LeetCode Solution ====================
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr) return 0;

        int left = maxDepth(root->left);
        int right = maxDepth(root->right);

        return 1 + max(left, right);
    }
};

// ==================== Local Testing ====================
int main() {
    /*
        Sample Tree:
              3
             / \
            9  20
               \
               7

        Maximum Depth = 3
    */

    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->right = new TreeNode(7);

    Solution sol;
    cout << "Maximum Depth of Tree: " << sol.maxDepth(root) << endl;

    return 0;
}
