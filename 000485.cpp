//IamMradul
#include <bits/stdc++.h>
using namespace std;

// ---------------- LeetCode Solution Function ----------------
// This function finds the maximum number of consecutive 1s in a binary array.
int findMaxConsecutiveOnes(vector<int>& nums) {
    int maxCount = 0, count = 0;
    for (int num : nums) {
        if (num == 1) {
            count++;
            maxCount = max(maxCount, count);
        } else {
            count = 0;
        }
    }
    return maxCount;
}
// ---------------- End of LeetCode Solution ----------------

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements (0s and 1s): ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int result = findMaxConsecutiveOnes(nums);
    cout << "Maximum consecutive 1s: " << result << endl;

    return 0;
}
