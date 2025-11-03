// ============================================================================
// 🧑‍💻 Author: Mradul Gupta
// 🌐 GitHub Username: IamMradul
// 🔗 GitHub Profile: https://github.com/IamMradul
// 🧩 LeetCode Username: Mradul_mg
// 🔗 LeetCode Profile: https://leetcode.com/u/Mradul_mg/
// ============================================================================
//
// 🧠 Problem: 19. Remove Nth Node From End of List
// 🔗 LeetCode Problem Link: https://leetcode.com/problems/remove-nth-node-from-end-of-list/
//
// 📜 Description:
//      Given the head of a linked list, remove the nth node from the end of the list
//      and return its head.
//
// 💡 Example:
//      Input: head = [1,2,3,4,5], n = 2
//      Output: [1,2,3,5]
//
// 🕒 Time Complexity: O(L) — where L is the length of the linked list
// 💾 Space Complexity: O(1)
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head) return nullptr;

        int cnt = 0;
        ListNode* temp = head;

        // Count total nodes
        while (temp != nullptr) {
            cnt++;
            temp = temp->next;
        }

        // If we need to remove the first node
        if (n == cnt) {
            ListNode* toDelete = head;
            head = head->next;
            delete toDelete;
            return head;
        }

        // Traverse to the node just before the target
        temp = head;
        for (int i = 1; i < cnt - n; i++) {
            temp = temp->next;
        }

        // Remove nth node from end
        ListNode* toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;

        return head;
    }
};

// ============================================================================
// 🧪 Main Function for Testing (Local Testing Only)
// ============================================================================
int main() {
    // Create Linked List: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    int n = 2;
    Solution sol;
    ListNode* result = sol.removeNthFromEnd(head, n);

    // Print updated list
    cout << "Updated Linked List after removing " << n << "th node from end: ";
    while (result) {
        cout << result->val;
        if (result->next) cout << " -> ";
        result = result->next;
    }
    cout << endl;

    // ✅ Expected Output: 1 -> 2 -> 3 -> 5
    return 0;
}
