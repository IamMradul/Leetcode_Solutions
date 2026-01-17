/*
====================================================
Author: Mradul Gupta
GitHub Username: IamMradul
GitHub Profile: https://github.com/IamMradul
LeetCode Username: Mradul_mg
LeetCode Profile: https://leetcode.com/u/Mradul_mg/

LeetCode Problem: 94. Binary Tree Inorder Traversal
Problem Link: https://leetcode.com/problems/binary-tree-inorder-traversal/

Time Complexity: O(n)
Space Complexity: O(n)   // recursion stack + result vector
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
    vector<int> res;

    void inorder(TreeNode* root) {
        if (root == nullptr) return;

        inorder(root->left);
        res.push_back(root->val);
        inorder(root->right);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        inorder(root);
        return res;
    }
};

// ==================== Local Testing ====================
int main() {
    /*
        Sample Tree:
              1
               \
                2
               /
              3

        Inorder Traversal: [1, 3, 2]
    */

    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    Solution sol;
    vector<int> result = sol.inorderTraversal(root);

    cout << "Inorder Traversal: ";
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
