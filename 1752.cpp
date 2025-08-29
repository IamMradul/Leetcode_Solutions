#include <bits/stdc++.h>
using namespace std;

// ---------------- LeetCode Solution Function ----------------
// This function checks if the given array is sorted and rotated.
// Original logic from your LeetCode solution.
bool check(vector<int>& nums) {
    int n = nums.size();
    int count = 0;

    // Compare each element with its next element (circular check using modulo)
    for (int i = 0; i < n; ++i) {
        if (nums[i] > nums[(i + 1) % n]) {
            count++;
        }
    }

    return count <= 1; // If there is at most one rotation point, return true
}
// ---------------- End of LeetCode Solution ----------------

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    // Call the function (LeetCode solution part)
    if (check(nums)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

    return 0;
}
