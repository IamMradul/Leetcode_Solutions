/*
 * Author: Mradul Gupta
 * GitHub Username: IamMradul
 *
 * LeetCode Problem: 142. Linked List Cycle II
 * Link: https://leetcode.com/problems/linked-list-cycle-ii/
 *
 * Problem Description:
 * Given the head of a linked list, return the node where the cycle begins. 
 * If there is no cycle, return NULL.
 *
 * Approach (Floyd’s Tortoise and Hare Algorithm):
 * - Use two pointers, `slow` and `fast`.
 * - Move `slow` by 1 step and `fast` by 2 steps.
 * - If they meet, a cycle exists.
 * - To find the starting node of the cycle:
 *   - Move `slow` to the head.
 *   - Move both pointers one step at a time.
 *   - The point where they meet again is the start of the cycle.
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
    ListNode(int x) : val(x), next(NULL) {}
};

// ---------------- LeetCode Solution ----------------
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                slow = head;
                while (slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
        }
        return NULL;
    }
};
// ---------------------------------------------------

// Helper functions for testing
void printCycleStart(ListNode* head, ListNode* cycleStart) {
    if (!cycleStart)
        cout << "No cycle detected." << endl;
    else
        cout << "Cycle detected at node with value: " << cycleStart->val << endl;
}

int main() {
    // Create linked list: 3 -> 2 -> 0 -> -4
    ListNode* head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(-4);

    // Create a cycle: tail connects to node with value 2
    head->next->next->next->next = head->next;

    Solution sol;
    ListNode* cycleStart = sol.detectCycle(head);

    printCycleStart(head, cycleStart);

    return 0;
}
