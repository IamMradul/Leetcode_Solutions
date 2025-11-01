/*
 * Author: Mradul Gupta
 * GitHub Username: IamMradul
 *
 * LeetCode Problem: 74. Search a 2D Matrix
 * Link: https://leetcode.com/problems/search-a-2d-matrix/
 *
 * Problem Description:
 * Write an efficient algorithm that searches for a value in an m x n integer matrix. 
 * This matrix has the following properties:
 * - Integers in each row are sorted from left to right.
 * - The first integer of each row is greater than the last integer of the previous row.
 *
 * Approach:
 * - Treat the 2D matrix as a 1D sorted array of size n * m.
 * - Apply binary search:
 *      mid index → (row = mid / m, col = mid % m).
 * - Compare matrix[row][col] with target and adjust search range accordingly.
 *
 * Time Complexity: O(log(n * m))
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
 
         int low = 0, high = n * m - 1;
         while (low <= high) {
             int mid = (low + high) / 2;
             int row = mid / m, col = mid % m;
 
             if (matrix[row][col] == target) return true;
             else if (matrix[row][col] < target) low = mid + 1;
             else high = mid - 1;
         }
         return false;
     }
 };
 // ---------------------------------------------------
 
 // Example usage with test cases
 int main() {
     Solution sol;
     vector<vector<int>> matrix = {
         {1, 3, 5, 7},
         {10, 11, 16, 20},
         {23, 30, 34, 60}
     };
 
     int target1 = 3;
     int target2 = 13;
 
     cout << "Searching for " << target1 << ": "
          << (sol.searchMatrix(matrix, target1) ? "Found ✅" : "Not Found ❌") 
          << endl;
 
     cout << "Searching for " << target2 << ": "
          << (sol.searchMatrix(matrix, target2) ? "Found ✅" : "Not Found ❌") 
          << endl;
 
     return 0;
 }
 