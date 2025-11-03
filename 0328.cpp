// ============================================================================
// 🧑‍💻 Author: Mradul Gupta
// 🌐 GitHub Username: IamMradul
// 🔗 GitHub Profile: https://github.com/IamMradul
// 🧩 LeetCode Username: Mradul_mg
// 🔗 LeetCode Profile: https://leetcode.com/u/Mradul_mg/
// ============================================================================
//
// 🧠 Problem: 328. Odd Even Linked List
// 🔗 LeetCode Problem Link: https://leetcode.com/problems/odd-even-linked-list/
//
// 📜 Description:
//      Given the head of a singly linked list, group all the nodes with odd 
//      indices together followed by the nodes with even indices, and return 
//      the reordered list. 
//
//      The first node is considered odd, the second even, and so on.
//      You must solve it in O(1) extra space complexity and O(n) time complexity.
//
// 💡 Example:
//      Input:  head = [1,2,3,4,5]
//      Output: [1,3,5,2,4]
//
// 🕒 Time Complexity: O(n)
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
    ListNode* oddEvenList(ListNode* head) {
        // Base case: if list is empty or has only one node
        if (!head || !head->next) return head;

        ListNode* odd = head;            // Pointer for odd-indexed nodes
        ListNode* even = head->next;     // Pointer for even-indexed nodes
        ListNode* evenHead = even;       // Save start of even list for later connection

        // Rearrange nodes
        while (even && even->next) {
            odd->next = even->next;
            odd = odd->next;

            even->next = odd->next;
            even = even->next;
        }

        // Connect odd list with even list
        odd->next = evenHead;

        return head;
    }
};

// ============================================================================
// 🧪 Main Function for Testing (for local validation)
// ============================================================================
int main() {
    // Create Linked List: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    // Create Solution object and apply function
    Solution sol;
    ListNode* result = sol.oddEvenList(head);

    // Print the reordered linked list
    cout << "Reordered Linked List: ";
    while (result) {
        cout << result->val;
        if (result->next) cout << " -> ";
        result = result->next;
    }
    cout << endl;

    // ✅ Expected Output: 1 -> 3 -> 5 -> 2 -> 4
    return 0;
}
