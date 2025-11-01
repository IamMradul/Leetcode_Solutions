/*
 * Author: Mradul Gupta
 * GitHub Username: IamMradul
 *
 * LeetCode Problem: 1901. Find a Peak Element II
 * Link: https://leetcode.com/problems/find-a-peak-element-ii/
 *
 * Problem Description:
 * A peak element in a 2D grid is an element that is strictly greater than all of its
 * adjacent neighbors (top, bottom, left, right). Given a 2D grid of integers `arr`,
 * return the coordinates [row, col] of any peak element. It is guaranteed that a peak 
 * element exists.
 *
 * Approach:
 * - Apply binary search on columns.
 * - For each column `mid`, find the row index that has the maximum element.
 * - Compare this element with its left and right neighbors:
 *      - If it is greater than both → return coordinates.
 *      - If left neighbor is greater → search in left half.
 *      - Else → search in right half.
 *
 * Time Complexity: O(n * log m), where n = rows, m = columns
 * Space Complexity: O(1)
 */

 #include <bits/stdc++.h>
 using namespace std;
 
 // ---------------- LeetCode Solution ----------------
 class Solution {
 public:
     // Helper function: Find the row index of maximum element in a given column
     int maxElement(vector<vector<int>>& arr, int col) {
         int n = arr.size();
         int max_val = INT_MIN;
         int index = -1;
 
         for (int i = 0; i < n; i++) {
             if (arr[i][col] > max_val) {
                 max_val = arr[i][col];
                 index = i;
             }
         }
         return index;
     }
 
     // Main function: Find peak element in the 2D grid
     vector<int> findPeakGrid(vector<vector<int>>& arr) {
         int n = arr.size();     
         int m = arr[0].size();  
         int low = 0;           
         int high = m - 1;      
 
         while (low <= high) {
             int mid = (low + high) / 2;
 
             int row = maxElement(arr, mid);
 
             int left = mid - 1 >= 0 ? arr[row][mid - 1] : INT_MIN;
             int right = mid + 1 < m ? arr[row][mid + 1] : INT_MIN;
 
             if (arr[row][mid] > left && arr[row][mid] > right) {
                 return {row, mid};
             } 
             else if (left > arr[row][mid]) {
                 high = mid - 1; // move left
             } 
             else {
                 low = mid + 1; // move right
             }
         }
 
         return {-1, -1}; // No peak found (though guaranteed by problem statement)
     }
 };
 // ---------------------------------------------------
 
 // Example usage with test cases
 int main() {
     Solution sol;
     vector<vector<int>> arr = {
         {10, 8, 10, 10},
         {14, 13, 12, 11},
         {15, 9, 11, 21},
         {16, 17, 19, 20}
     };
 
     vector<int> peak = sol.findPeakGrid(arr);
     cout << "Peak found at position: [" << peak[0] << ", " << peak[1] << "]" << endl;
 
     return 0;
 }
 