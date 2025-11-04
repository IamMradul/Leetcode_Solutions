// ============================================================================
// 🧑‍💻 Author: Mradul Gupta
// 🌐 GitHub Username: IamMradul
// 🔗 GitHub Profile: https://github.com/IamMradul
// 🧩 LeetCode Username: Mradul_mg
// 🔗 LeetCode Profile: https://leetcode.com/u/Mradul_mg/
// ============================================================================
//
// 🧠 Problem: 2095. Delete the Middle Node of a Linked List
// 🔗 LeetCode Problem Link: https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/
//
// 📜 Description:
//      You are given the head of a linked list. Delete the middle node, and return the head
//      of the modified linked list.
//
//      The middle node of a linked list of size n is the ⌊n / 2⌋th node from the start,
//      using 0-based indexing.
//
// 💡 Example:
//      Input: head = [1,3,4,7,1,2,6]
//      Output: [1,3,4,1,2,6]
//
// 🕒 Time Complexity: O(N) — Traverses the list once using slow and fast pointers.
// 💾 Space Complexity: O(1) — Constant extra space used.
// ============================================================================

#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// ============================================================================
// 💡 LeetCode Solution Class
// ============================================================================
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if (!head || !head->next) return NULL;

        // If only two nodes exist, delete the second one
        if (!head->next->next) {
            ListNode* temp = head->next;
            head->next = NULL;
            delete temp;
            return head;
        }

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = head;

        // Move slow one step, fast two steps
        while (fast != NULL && fast->next != NULL) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        // Delete the middle node
        ListNode* toDelete = slow;
        prev->next = slow->next;
        delete toDelete;

        return head;
    }
};

// ============================================================================
// 🧪 Main Function for Local Testing
// ============================================================================
int main() {
    // Create Linked List: 1 -> 3 -> 4 -> 7 -> 1 -> 2 -> 6
    ListNode* head = new ListNode(1);
    head->next = new ListNode(3);
    head->next->next = new ListNode(4);
    head->next->next->next = new ListNode(7);
    head->next->next->next->next = new ListNode(1);
    head->next->next->next->next->next = new ListNode(2);
    head->next->next->next->next->next->next = new ListNode(6);

    Solution sol;
    ListNode* result = sol.deleteMiddle(head);

    // Print updated list
    cout << "Linked List after deleting middle node: ";
    while (result) {
        cout << result->val;
        if (result->next) cout << " -> ";
        result = result->next;
    }
    cout << endl;

    // ✅ Expected Output: 1 -> 3 -> 4 -> 1 -> 2 -> 6
    return 0;
}
