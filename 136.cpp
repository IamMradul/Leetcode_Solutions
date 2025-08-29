#include <bits/stdc++.h>
using namespace std;

// ---------------- LeetCode Solution Function ----------------
// This function finds the single number in an array where every element 
// appears twice except for one. It uses XOR operation.
int singleNumber(vector<int>& nums) {
    int x = 0;
    for (int i = 0; i < nums.size(); i++) {
        x ^= nums[i]; // XOR cancels out pairs, leaving the unique element
    }
    return x;
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

    int result = singleNumber(nums);
    cout << "The single number is: " << result << endl;

    return 0;
}
