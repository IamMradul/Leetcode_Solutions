/**
 * @file LinkedListCycle.cpp
 * @brief Detects if a singly linked list contains a cycle using Floyd's Cycle Detection Algorithm.
 *
 * 🧩 Problem Link: https://leetcode.com/problems/linked-list-cycle/
 *
 * 👤 Author: Mradul Gupta
 * 🔗 GitHub: https://github.com/IamMradul
 *
 * This solution uses two pointers (slow and fast). 
 * The slow pointer moves one step at a time, while the fast pointer moves two steps. 
 * If they ever meet, a cycle exists in the linked list.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */

#include <iostream>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    /**
     * @brief Determines whether the linked list has a cycle.
     * 
     * @param head Pointer to the head of the linked list.
     * @return true if there is a cycle, false otherwise.
     */
    bool hasCycle(ListNode *head) {
        if (head == NULL || head->next == NULL)
            return false;

        ListNode *slow = head;
        ListNode *fast = head;

        // Move slow by 1 and fast by 2 steps
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;

            // If slow and fast meet, a cycle exists
            if (slow == fast)
                return true;
        }
        return false;
    }
};

// Example usage for local testing
int main() {
    // Creating a test linked list with a cycle
    ListNode *head = new ListNode(3);
    ListNode *node2 = new ListNode(2);
    ListNode *node3 = new ListNode(0);
    ListNode *node4 = new ListNode(-4);

    head->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node2; // Creates a cycle here

    Solution sol;
    bool result = sol.hasCycle(head);

    cout << (result ? "Cycle detected ✅" : "No cycle ❌") << endl;

    // Cleanup skipped intentionally since it contains a cycle
    return 0;
}
