/*
 * Author: Mradul Gupta
 * GitHub Username: IamMradul
 * GitHub Profile: https://github.com/IamMradul
 * LeetCode Username: Mradul_mg
 * LeetCode Profile: https://leetcode.com/u/Mradul_mg/
 *
 * LeetCode Problem: 61. Rotate List
 * Link: https://leetcode.com/problems/rotate-list/
 *
 * Approach: Convert list to circular, then break at correct position
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */

#include <iostream>
using namespace std;

/* =======================
   Definition of ListNode
   ======================= */
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

/* =======================
   LeetCode Solution Class
   ======================= */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0)
            return head;

        int len = 1;
        ListNode* tail = head;

        // Find length and tail
        while (tail->next) {
            tail = tail->next;
            len++;
        }

        // Make list circular
        tail->next = head;

        k = k % len;
        int stepsToNewTail = len - k;

        ListNode* newTail = head;
        for (int i = 1; i < stepsToNewTail; i++) {
            newTail = newTail->next;
        }

        ListNode* newHead = newTail->next;
        newTail->next = nullptr;  // break the circle

        return newHead;
    }
};

/* =======================
   Utility Function
   ======================= */
void printList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

/* =======================
   Main Function (Testing)
   ======================= */
int main() {
    /*
     * Test Case 1:
     * Input:  1 -> 2 -> 3 -> 4 -> 5, k = 2
     * Output: 4 -> 5 -> 1 -> 2 -> 3
     */

    ListNode* head1 = new ListNode(1,
                         new ListNode(2,
                         new ListNode(3,
                         new ListNode(4,
                         new ListNode(5)))));

    cout << "Original List: ";
    printList(head1);

    Solution sol;
    int k1 = 2;
    head1 = sol.rotateRight(head1, k1);

    cout << "After rotating k = " << k1 << ": ";
    printList(head1);

    /*
     * Test Case 2:
     * Input:  0 -> 1 -> 2, k = 4
     * Output: 2 -> 0 -> 1
     */

    ListNode* head2 = new ListNode(0,
                         new ListNode(1,
                         new ListNode(2)));

    cout << "\nOriginal List: ";
    printList(head2);

    int k2 = 4;
    head2 = sol.rotateRight(head2, k2);

    cout << "After rotating k = " << k2 << ": ";
    printList(head2);

    /*
     * Test Case 3:
     * Input:  1, k = 10
     * Output: 1
     */

    ListNode* head3 = new ListNode(1);

    cout << "\nOriginal List: ";
    printList(head3);

    int k3 = 10;
    head3 = sol.rotateRight(head3, k3);

    cout << "After rotating k = " << k3 << ": ";
    printList(head3);

    return 0;
}
