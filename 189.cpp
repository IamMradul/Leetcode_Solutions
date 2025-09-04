//IamMradul
#include <bits/stdc++.h>
using namespace std;

// ---------------- LeetCode Solution Function ----------------
// This function rotates the array to the right by k steps.
void rotate(vector<int>& nums, int k) {
    int n = nums.size();
    k %= n; // handle cases where k > n

    // Reverse the entire array
    reverse(nums.begin(), nums.end());

    // Reverse first k elements
    reverse(nums.begin(), nums.begin() + k);

    // Reverse the remaining elements
    reverse(nums.begin() + k, nums.end());
}
// ---------------- End of LeetCode Solution ----------------

int main() {
    int n, k;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << "Enter value of k: ";
    cin >> k;

    // Call the rotate function (LeetCode logic)
    rotate(nums, k);

    cout << "Array after rotation: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
