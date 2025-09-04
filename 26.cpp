//IamMradul
#include <bits/stdc++.h>
using namespace std;

// ---------------- LeetCode Solution Function ----------------
// This function removes duplicates from a sorted array in-place.
// Returns the number of unique elements (k).
int removeDuplicates(vector<int>& nums) {
    if (nums.empty()) return 0;

    int k = 1; // index for placing next unique element

    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] != nums[k - 1]) {
            nums[k] = nums[i]; // place unique element at position k
            k++;
        }
    }

    return k; // k is the count of unique elements
}
// ---------------- End of LeetCode Solution ----------------

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter sorted elements (with duplicates): ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    // Call the function (LeetCode logic)
    int k = removeDuplicates(nums);

    cout << "Number of unique elements: " << k << endl;
    cout << "Array after removing duplicates: ";
    for (int i = 0; i < k; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}
