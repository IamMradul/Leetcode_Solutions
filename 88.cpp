/*
Author: Mradul Gupta
GitHub Username: IamMradul

LeetCode Question: Merge Sorted Array
Link: https://leetcode.com/problems/merge-sorted-array/
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;

        while (i >= 0 && j >= 0) {
            if (nums1[i] < nums2[j]) {
                nums1[k] = nums2[j];
                j--;
            } else {
                nums1[k] = nums1[i];
                i--;
            }
            k--;
        }

        while (j >= 0) {
            nums1[k] = nums2[j];
            j--;
            k--;
        }
    }
};

// Main function for testing
int main() {
    Solution sol;

    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    vector<int> nums2 = {2, 5, 6};
    int m = 3, n = 3;

    cout << "Before merge: ";
    for (int x : nums1) cout << x << " ";
    cout << endl;

    sol.merge(nums1, m, nums2, n);

    cout << "After merge: ";
    for (int x : nums1) cout << x << " ";
    cout << endl;

    // Additional test case
    vector<int> nums3 = {4, 5, 6, 0, 0, 0};
    vector<int> nums4 = {1, 2, 3};
    m = 3, n = 3;

    sol.merge(nums3, m, nums4, n);

    cout << "Another test case result: ";
    for (int x : nums3) cout << x << " ";
    cout << endl;

    return 0;
}
