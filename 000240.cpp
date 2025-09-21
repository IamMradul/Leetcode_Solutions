/*
 * Author: Mradul Gupta
 * GitHub Username: IamMradul
 *
 * LeetCode Problem: 240. Search a 2D Matrix II
 * Link: https://leetcode.com/problems/search-a-2d-matrix-ii/
 *
 * Problem Description:
 * Write an efficient algorithm that searches for a value in an m x n integer matrix. 
 * This matrix has the following properties:
 * - Integers in each row are sorted in ascending order from left to right.
 * - Integers in each column are sorted in ascending order from top to bottom.
 *
 * Approach:
 * - Start from the top-right corner.
 * - If the current number equals the target, return true.
 * - If the current number is greater than the target, move left.
 * - If the current number is smaller than the target, move down.
 *
 * Time Complexity: O(n + m), where n = number of rows, m = number of columns
 * Space Complexity: O(1)
 */

 #include <bits/stdc++.h>
 using namespace std;
 
 // ---------------- LeetCode Solution ----------------
 class Solution {
 public:
     bool searchMatrix(vector<vector<int>>& matrix, int target) {
         int n = matrix.size();
         int m = matrix[0].size();
         int row = 0;
         int col = m - 1;
 
         while (row < n && col >= 0) {
             if (matrix[row][col] == target) {
                 return true;
             } else if (matrix[row][col] > target) {
                 col--; // move left
             } else {
                 row++; // move down
             }
         }
         return false;
     }
 };
 // ---------------------------------------------------
 
 // Example usage with test cases
 int main() {
     Solution sol;
     vector<vector<int>> matrix = {
         {1, 4, 7, 11, 15},
         {2, 5, 8, 12, 19},
         {3, 6, 9, 16, 22},
         {10, 13, 14, 17, 24},
         {18, 21, 23, 26, 30}
     };
 
     int target1 = 5;
     int target2 = 20;
 
     cout << "Searching for " << target1 << ": "
          << (sol.searchMatrix(matrix, target1) ? "Found ✅" : "Not Found ❌") 
          << endl;
 
     cout << "Searching for " << target2 << ": "
          << (sol.searchMatrix(matrix, target2) ? "Found ✅" : "Not Found ❌") 
          << endl;
 
     return 0;
 }
 