/*
 * Author: Mradul Gupta
 * GitHub Username: IamMradul
 *
 * LeetCode Problem: 206. Reverse Linked List
 * Link: https://leetcode.com/problems/reverse-linked-list/
 *
 * Problem Description:
 * Given the head of a singly linked list, reverse the list and return the reversed list.
 *
 * Approach:
 * - Use three pointers: `prev`, `curr`, and `nextNode`.
 * - Traverse the list while reversing the `next` pointer of each node.
 * - Move the `prev` and `curr` pointers one step forward in each iteration.
 * - Finally, return `prev` as the new head of the reversed list.
 *
 * Time Complexity: O(n), where n = number of nodes in the linked list
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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;     
        ListNode* curr = head;         
        while (curr != nullptr) {      
            ListNode* nextNode = curr->next;  
            curr->next = prev;               
            prev = curr;                     
            curr = nextNode;                 
        }
        return prev;  
    }
};
// ---------------------------------------------------

// Helper functions for testing
void printList(ListNode* head) {
    while (head) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main() {
    // Create linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    cout << "Original list: ";
    printList(head);

    Solution sol;
    ListNode* reversedHead = sol.reverseList(head);

    cout << "Reversed list: ";
    printList(reversedHead);

    return 0;
}
