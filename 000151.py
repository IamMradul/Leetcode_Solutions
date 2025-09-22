"""
Author: Mradul Gupta
GitHub Username: IamMradul

LeetCode Problem: 151. Reverse Words in a String
Link: https://leetcode.com/problems/reverse-words-in-a-string/

Problem Description:
Given an input string `s`, reverse the order of the words. 
A word is defined as a sequence of non-space characters. 
The words in `s` will be separated by at least one space. 
Return a string of the words in reverse order concatenated by a single space.

Approach:
- Split the string `s` into words using split().
- Reverse the list of words.
- Join the reversed list with single spaces to form the final string.

Time Complexity: O(n), where n = length of the string
Space Complexity: O(n) for the list of words
"""

# ---------------- LeetCode Solution ----------------
class Solution:
    def reverseWords(self, s: str) -> str:
        lst = s.split()
        lst.reverse()
        return '    '.join(lst)
# ---------------------------------------------------

# Example usage with test case
if __name__ == "__main__":
    sol = Solution()
    s = "  the sky   is blue  "
    print("Original string: '{}'".format(s))
    result = sol.reverseWords(s)
    print("Reversed words: '{}'".format(result))
