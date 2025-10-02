/*
 * Author: Mradul Gupta
 * GitHub Username: IamMradul
 *
 * LeetCode Problem: 451. Sort Characters By Frequency
 * Link: https://leetcode.com/problems/sort-characters-by-frequency/
 *
 * Problem Description:
 * Given a string `s`, sort it in decreasing order based on the frequency of characters.
 * Return the sorted string. Characters with higher frequency should appear first.
 *
 * Approach:
 * - Use an unordered_map to count the frequency of each character.
 * - Store the map in a vector of pairs (char, frequency).
 * - Sort the vector in decreasing order based on frequency.
 * - Build the result string by repeating characters according to their frequency.
 *
 * Time Complexity: O(n log n), where n = length of string s (sorting the vector)
 * Space Complexity: O(n), for frequency map and result string
 */

 #include <bits/stdc++.h>
 using namespace std;
 
 // ---------------- LeetCode Solution ----------------
 class Solution {
 public:
     string frequencySort(string s) {
         unordered_map<char,int> freq;
         for (char c : s){
             freq[c]++;
         } 
 
         vector<pair<char,int>> v(freq.begin(), freq.end());
         sort(v.begin(), v.end(), [](auto &a, auto &b){
             return a.second > b.second;
         });
 
         string res;
         for (auto &p : v) {
             res += string(p.second, p.first);
         }
 
         return res;
     }
 };
 // ---------------------------------------------------
 
 // Example usage with test case
 int main() {
     Solution sol;
 
     string s1 = "tree";
     string s2 = "cccaaa";
     string s3 = "Aabb";
 
     cout << "Input: " << s1 << " → Frequency Sorted: " << sol.frequencySort(s1) << endl;
     cout << "Input: " << s2 << " → Frequency Sorted: " << sol.frequencySort(s2) << endl;
     cout << "Input: " << s3 << " → Frequency Sorted: " << sol.frequencySort(s3) << endl;
 
     return 0;
 }
 