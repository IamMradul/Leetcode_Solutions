/*
 * Author: Mradul Gupta
 * GitHub: https://github.com/MG26-spec
 * Problem: Minimum Number of Days to Make m Bouquets (LeetCode)
 */

 #include <bits/stdc++.h>
 using namespace std;
 
 /* --------- LeetCode Solution Starts --------- */
 class Solution { 
 public:
     bool possible(vector<int> &arr, int day, int m, int k) {
         int n = arr.size(); 
         int cnt = 0;
         int noOfB = 0;
         for (int i = 0; i < n; i++) {
             if (arr[i] <= day) {
                 cnt++;
             } else {
                 noOfB += (cnt / k);
                 cnt = 0;
             }
         }
         noOfB += (cnt / k);
         return noOfB >= m;
     }
 
     int minDays(vector<int>& bloomDay, int m, int k) {
         long long val = (long long)m * k;
         int n = bloomDay.size(); 
         if (val > n) return -1; 
    
         int mini = INT_MAX, maxi = INT_MIN;
         for (int i = 0; i < n; i++) {
             mini = min(mini, bloomDay[i]);
             maxi = max(maxi, bloomDay[i]);
         }
 
         int low = mini, high = maxi;
         while (low <= high) {
             int mid = low + (high - low) / 2;
             if (possible(bloomDay, mid, m, k)) {
                 high = mid - 1;
             } else {
                 low = mid + 1;
             }
         }
         return low;
     }
 };
 /* --------- LeetCode Solution Ends --------- */
 
 int main() {
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
 
     int n, m, k;
     cout << "Enter number of flowers: ";
     cin >> n;
 
     vector<int> bloomDay(n);
     cout << "Enter bloom days: ";
     for (int i = 0; i < n; i++) {
         cin >> bloomDay[i];
     }
 
     cout << "Enter number of bouquets (m): ";
     cin >> m;
     cout << "Enter flowers per bouquet (k): ";
     cin >> k;
 
     Solution sol;
     int result = sol.minDays(bloomDay, m, k);
     cout << "Minimum days required: " << result << "\n";
 
     return 0;
 }
 