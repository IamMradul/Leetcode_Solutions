/*
 * Author: Mradul Gupta
 * GitHub Username: IamMradul
 *
 * LeetCode Problem: 237. Delete Node in a Linked List
 * Link: https://leetcode.com/problems/delete-node-in-a-linked-list/
 *
 * Problem Description:
 * Write a function to delete a node (except the tail) in a singly linked list, 
 * given only access to that node. The linked list will have at least two nodes.
 *
 * Approach:
 * - Copy the value of the next node to the current node.
 * - Update the current node's next pointer to skip the next node.
 * - Delete the next node to free memory.
 *
 * Time Complexity: O(1)
 * Space Complexity: O(1)
 */

 #include <bits/stdc++.h>
 using namespace std;
 
 // Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
 
 // ---------------- LeetCode Solution ----------------
 class Solution {
 public:
     void deleteNode(ListNode* node) {
         node->val = node->next->val;
         ListNode* temp = node->next;
         node->next = node->next->next;
         delete temp;
     }
 };
 // ---------------------------------------------------
 
 // Helper functions for demonstration
 void printList(ListNode* head) {
     while (head) {
         cout << head->val << " -> ";
         head = head->next;
     }
     cout << "NULL" << endl;
 }
 
 int main() {
     // Create linked list: 4 -> 5 -> 1 -> 9
     ListNode* head = new ListNode(4);
     head->next = new ListNode(5);
     head->next->next = new ListNode(1);
     head->next->next->next = new ListNode(9);
 
     cout << "Original list: ";
     printList(head);
 
     Solution sol;
     // Delete node with value 5
     sol.deleteNode(head->next);
 
     cout << "After deleting node 5: ";
     printList(head);
 
     return 0;
 }
 