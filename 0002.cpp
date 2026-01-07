/*
 * Author: Mradul Gupta
 * GitHub Username: IamMradul
 * GitHub Profile: https://github.com/IamMradul
 * LeetCode Username: Mradul_mg
 * LeetCode Profile: https://leetcode.com/u/Mradul_mg/
 *
 * LeetCode Problem: 2. Add Two Numbers
 * Link: https://leetcode.com/problems/add-two-numbers/
 *
 * Approach: Digit-by-digit addition with carry
 * Time Complexity: O(max(n, m))
 * Space Complexity: O(max(n, m))
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* curr = &dummy;
        int carry = 0;

        while (l1 || l2 || carry) {
            int sum = carry;

            if (l1) {
                sum += l1->val;
                l1 = l1->next;
            }

            if (l2) {
                sum += l2->val;
                l2 = l2->next;
            }

            carry = sum / 10;
            curr->next = new ListNode(sum % 10);
            curr = curr->next;
        }

        return dummy.next;
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
     * Input:
     * l1 = 2 -> 4 -> 3   (342)
     * l2 = 5 -> 6 -> 4   (465)
     * Output:
     * 7 -> 0 -> 8        (807)
     */

    ListNode* l1 = new ListNode(2,
                     new ListNode(4,
                     new ListNode(3)));

    ListNode* l2 = new ListNode(5,
                     new ListNode(6,
                     new ListNode(4)));

    cout << "List 1: ";
    printList(l1);
    cout << "List 2: ";
    printList(l2);

    Solution sol;
    ListNode* result = sol.addTwoNumbers(l1, l2);

    cout << "Result: ";
    printList(result);

    /*
     * Test Case 2:
     * Input:
     * l1 = 0
     * l2 = 0
     * Output:
     * 0
     */

    ListNode* a = new ListNode(0);
    ListNode* b = new ListNode(0);

    cout << "\nList 1: ";
    printList(a);
    cout << "List 2: ";
    printList(b);

    result = sol.addTwoNumbers(a, b);

    cout << "Result: ";
    printList(result);

    return 0;
}
