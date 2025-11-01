/*
 * Author: Mradul Gupta
 * GitHub Username: IamMradul
 *
 * LeetCode Problem: 205. Isomorphic Strings
 * Link: https://leetcode.com/problems/isomorphic-strings/
 *
 * Problem Description:
 * Given two strings `s` and `t`, determine if they are isomorphic.
 * Two strings `s` and `t` are isomorphic if the characters in `s` can be replaced 
 * to get `t`. All occurrences of a character must be replaced with another character 
 * while preserving the order of characters. No two characters may map to the same 
 * character, but a character may map to itself.
 *
 * Approach:
 * - Use two hash maps:
 *      - mapST: maps characters of s → t
 *      - mapTS: maps characters of t → s
 * - Traverse both strings simultaneously:
 *      - If a mapping conflict occurs in either map, return false.
 * - If the entire traversal completes without conflict, return true.
 *
 * Time Complexity: O(n), where n = length of s (or t)
 * Space Complexity: O(1) — since we store at most 256 characters in the maps
 */

 #include <bits/stdc++.h>
 using namespace std;
 
 // ---------------- LeetCode Solution ----------------
 class Solution {
 public:
     bool isIsomorphic(string s, string t) {
         if (s.size() != t.size()) return false;
         
         unordered_map<char, char> mapST;  
         unordered_map<char, char> mapTS;  
 
         for (int i = 0; i < s.size(); i++) {
             char c1 = s[i];
             char c2 = t[i];
 
             if (mapST.count(c1) && mapST[c1] != c2) return false;
             if (mapTS.count(c2) && mapTS[c2] != c1) return false;
 
             mapST[c1] = c2;
             mapTS[c2] = c1;
         }
         return true;
     }
 };
 // ---------------------------------------------------
 
 // Example usage with test case
 int main() {
     Solution sol;
 
     string s1 = "egg", t1 = "add";
     string s2 = "foo", t2 = "bar";
     string s3 = "paper", t3 = "title";
 
     cout << "Input: (egg, add) → " << (sol.isIsomorphic(s1, t1) ? "True ✅" : "False ❌") << endl;
     cout << "Input: (foo, bar) → " << (sol.isIsomorphic(s2, t2) ? "True ✅" : "False ❌") << endl;
     cout << "Input: (paper, title) → " << (sol.isIsomorphic(s3, t3) ? "True ✅" : "False ❌") << endl;
 
     return 0;
 }
 