// Author: Mradul Gupta
// GitHub: IamMradul
// --------------------------------------
// LeetCode Solution: minEatingSpeed (Koko Eating Bananas)
// --------------------------------------

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = *max_element(piles.begin(), piles.end());
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            long long totalHours = 0;
            
            for (int pile : piles) {
                totalHours += (pile + mid - 1) / mid; // ceiling division
            }
            
            if (totalHours <= h) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        return low;
    }
};

int main() {
    Solution obj;
    vector<int> piles = {3, 6, 7, 11};
    int h = 8;
    
    cout << "Minimum eating speed: " << obj.minEatingSpeed(piles, h) << endl;
    
    return 0;
}
