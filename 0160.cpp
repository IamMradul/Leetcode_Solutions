/*
 * Author: Mradul Gupta
 * GitHub Username: IamMradul
 * GitHub Profile: https://github.com/IamMradul
 * LeetCode Username: Mradul_mg
 * LeetCode Profile: https://leetcode.com/u/Mradul_mg/
 *
 * LeetCode Problem: 160. Intersection of Two Linked Lists
 * Link: https://leetcode.com/problems/intersection-of-two-linked-lists/
 *
 * Approach: Two Pointer Technique
 * Time Complexity: O(n + m)
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
    ListNode(int x) : val(x), next(NULL) {}
};

/* =======================
   LeetCode Solution Class
   ======================= */
class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        if (!headA || !headB) return NULL;

        ListNode* t1 = headA;
        ListNode* t2 = headB;

        while (t1 != t2) {
            t1 = (t1 == NULL) ? headB : t1->next;
            t2 = (t2 == NULL) ? headA : t2->next;
        }
        return t1; // either intersection node or NULL
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
     * Test Case 1 (With Intersection):
     *
     * List A: 1 -> 2 -> 3
     *                    \
     *                     8 -> 9
     *                    /
     * List B:       4 -> 5
     *
     * Intersection Node Value: 8
     */

    ListNode* intersect = new ListNode(8);
    intersect->next = new ListNode(9);

    ListNode* headA = new ListNode(1);
    headA->next = new ListNode(2);
    headA->next->next = new ListNode(3);
    headA->next->next->next = intersect;

    ListNode* headB = new ListNode(4);
    headB->next = new ListNode(5);
    headB->next->next = intersect;

    cout << "List A: ";
    printList(headA);
    cout << "List B: ";
    printList(headB);

    Solution sol;
    ListNode* result = sol.getIntersectionNode(headA, headB);

    if (result)
        cout << "Intersection at node with value: " << result->val << endl;
    else
        cout << "No intersection found." << endl;

    /*
     * Test Case 2 (No Intersection)
     */

    ListNode* a = new ListNode(1);
    a->next = new ListNode(2);
    a->next->next = new ListNode(3);

    ListNode* b = new ListNode(4);
    b->next = new ListNode(5);

    cout << "\nList A: ";
    printList(a);
    cout << "List B: ";
    printList(b);

    result = sol.getIntersectionNode(a, b);

    if (result)
        cout << "Intersection at node with value: " << result->val << endl;
    else
        cout << "No intersection found." << endl;

    return 0;
}
