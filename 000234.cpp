/*
 * Author: Mradul Gupta
 * GitHub Username: IamMradul
 *
 * LeetCode Problem: 234. Palindrome Linked List
 * Link: https://leetcode.com/problems/palindrome-linked-list/
 *
 * Problem Description:
 * Given the head of a singly linked list, return true if it is a palindrome or false otherwise.
 *
 * Approach:
 * 1. Use two pointers (slow and fast) to find the middle of the linked list.
 * 2. Reverse the second half of the list.
 * 3. Compare the first half and the reversed second half node by node.
 * 4. If all corresponding values match, it's a palindrome.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */

#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// ---------------- LeetCode Solution ----------------
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;

        // Step 1: Find middle using slow and fast pointers
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Step 2: Reverse the second half
        ListNode* prev = nullptr;
        ListNode* curr = slow;
        while (curr) {
            ListNode* nextTemp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextTemp;
        }

        // Step 3: Compare first and second halves
        ListNode* left = head;
        ListNode* right = prev;
        while (right && left) {
            if (left->val != right->val) return false;
            left = left->next;
            right = right->next;
        }
        return true;
    }
};
// ---------------------------------------------------

// Helper functions for local testing
ListNode* createList(vector<int> vals) {
    if (vals.empty()) return nullptr;
    ListNode* head = new ListNode(vals[0]);
    ListNode* curr = head;
    for (int i = 1; i < vals.size(); i++) {
        curr->next = new ListNode(vals[i]);
        curr = curr->next;
    }
    return head;
}

int main() {
    Solution sol;

    // Example 1: Palindrome list [1,2,2,1]
    ListNode* head1 = createList({1, 2, 2, 1});
    cout << (sol.isPalindrome(head1) ? "true" : "false") << endl;

    // Example 2: Non-palindrome list [1,2]
    ListNode* head2 = createList({1, 2});
    cout << (sol.isPalindrome(head2) ? "true" : "false") << endl;

    return 0;
}
