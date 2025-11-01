//IamMradul
#include <bits/stdc++.h>
using namespace std;

// ---------------- LeetCode Solution Function ----------------
// This function finds the missing number in an array of size n that contains
// numbers from 0 to n (with one missing). It uses the sum formula.
int missingNumber(vector<int>& nums) {
    int n = nums.size();
    int total = n * (n + 1) / 2; // Sum of first n natural numbers (0 to n)

    for (int num : nums) {
        total -= num; // Subtract each number in the array
    }

    return total; // Remaining value is the missing number
}
// ---------------- End of LeetCode Solution ----------------

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements (from 0 to n, one missing): ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int result = missingNumber(nums);
    cout << "Missing number is: " << result << endl;

    return 0;
}
