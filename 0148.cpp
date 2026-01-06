/*
 * Author: Mradul Gupta
 * GitHub Username: IamMradul
 * GitHub Profile: https://github.com/IamMradul
 * LeetCode Username: Mradul_mg
 * LeetCode Profile: https://leetcode.com/u/Mradul_mg/
 *
 * LeetCode Problem: 148. Sort List
 * Link: https://leetcode.com/problems/sort-list/
 *
 * Approach: Merge Sort on Linked List
 * Time Complexity: O(n log n)
 * Space Complexity: O(log n) (recursion stack)
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
    // Merge two sorted linked lists
    ListNode* mergeTwoSortedLinkedLists(ListNode* list1, ListNode* list2) {
        ListNode dummy(-1);
        ListNode* tail = &dummy;

        while (list1 && list2) {
            if (list1->val <= list2->val) {
                tail->next = list1;
                list1 = list1->next;
            } else {
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next;
        }

        tail->next = (list1) ? list1 : list2;
        return dummy.next;
    }

    // Find middle of the linked list
    ListNode* findMiddle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    // Sort linked list using merge sort
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode* mid = findMiddle(head);
        ListNode* right = mid->next;
        mid->next = nullptr;

        ListNode* left = sortList(head);
        right = sortList(right);

        return mergeTwoSortedLinkedLists(left, right);
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
     * Input: 4 -> 2 -> 1 -> 3
     * Output: 1 -> 2 -> 3 -> 4
     */

    ListNode* head = new ListNode(4,
                        new ListNode(2,
                        new ListNode(1,
                        new ListNode(3))));

    cout << "Original List: ";
    printList(head);

    Solution sol;
    head = sol.sortList(head);

    cout << "Sorted List:   ";
    printList(head);

    /*
     * Test Case 2:
     * Input: -1 -> 5 -> 3 -> 4 -> 0
     * Output: -1 -> 0 -> 3 -> 4 -> 5
     */

    ListNode* head2 = new ListNode(-1,
                         new ListNode(5,
                         new ListNode(3,
                         new ListNode(4,
                         new ListNode(0)))));

    cout << "\nOriginal List: ";
    printList(head2);

    head2 = sol.sortList(head2);

    cout << "Sorted List:   ";
    printList(head2);

    return 0;
}
