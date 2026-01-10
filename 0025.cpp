/*
 * Author: Mradul Gupta
 * GitHub Username: IamMradul
 * GitHub Profile: https://github.com/IamMradul
 * LeetCode Username: Mradul_mg
 * LeetCode Profile: https://leetcode.com/u/Mradul_mg/
 *
 * LeetCode Problem: 25. Reverse Nodes in k-Group
 * Link: https://leetcode.com/problems/reverse-nodes-in-k-group/
 *
 * Approach: Iterative in-place reversal using dummy node
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;

        ListNode dummy(0);
        dummy.next = head;
        ListNode* groupPrev = &dummy;

        while (true) {
            ListNode* kth = getKthNode(groupPrev, k);
            if (!kth) break;

            ListNode* groupNext = kth->next;

            // Reverse k nodes
            ListNode* prev = groupNext;
            ListNode* curr = groupPrev->next;

            for (int i = 0; i < k; i++) {
                ListNode* temp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = temp;
            }

            // Reconnect reversed group
            ListNode* temp = groupPrev->next;
            groupPrev->next = kth;
            groupPrev = temp;
        }

        return dummy.next;
    }

private:
    ListNode* getKthNode(ListNode* curr, int k) {
        while (curr && k > 0) {
            curr = curr->next;
            k--;
        }
        return curr;
    }
};

/* =======================
   Utility Functions
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
     * Output: 2 -> 1 -> 4 -> 3 -> 5
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
    head1 = sol.reverseKGroup(head1, k1);

    cout << "After reversing k = " << k1 << ": ";
    printList(head1);

    /*
     * Test Case 2:
     * Input:  1 -> 2 -> 3 -> 4 -> 5, k = 3
     * Output: 3 -> 2 -> 1 -> 4 -> 5
     */

    ListNode* head2 = new ListNode(1,
                         new ListNode(2,
                         new ListNode(3,
                         new ListNode(4,
                         new ListNode(5)))));

    cout << "\nOriginal List: ";
    printList(head2);

    int k2 = 3;
    head2 = sol.reverseKGroup(head2, k2);

    cout << "After reversing k = " << k2 << ": ";
    printList(head2);

    /*
     * Test Case 3:
     * Input:  1 -> 2, k = 3
     * Output: 1 -> 2 (unchanged)
     */

    ListNode* head3 = new ListNode(1, new ListNode(2));

    cout << "\nOriginal List: ";
    printList(head3);

    int k3 = 3;
    head3 = sol.reverseKGroup(head3, k3);

    cout << "After reversing k = " << k3 << ": ";
    printList(head3);

    return 0;
}
