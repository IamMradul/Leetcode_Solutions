// ============================================================================
// 🧑‍💻 Author: Mradul Gupta
// 🌐 GitHub Username: IamMradul
// 🔗 GitHub Profile: https://github.com/IamMradul
// 🧩 LeetCode Username: Mradul_mg
// 🔗 LeetCode Profile: https://leetcode.com/u/Mradul_mg/
// ============================================================================
//
// 🧠 Problem: 148. Sort List
// 🔗 LeetCode Problem Link: https://leetcode.com/problems/sort-list/
//
// 📜 Description:
//      Given the head of a linked list, return the list after sorting it in 
//      ascending order. You must solve the problem in O(n log n) time complexity 
//      and with O(1) auxiliary space.
//
// 💡 Example:
//      Input: head = [4,2,1,3]
//      Output: [1,2,3,4]
//
// 🕒 Time Complexity: O(N log N) — Merge Sort on Linked List
// 💾 Space Complexity: O(log N) — Due to recursion stack
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
    // Merges two sorted linked lists into one sorted list
    ListNode* mergeTwoSortedLinkedLists(ListNode* list1, ListNode* list2) {
        ListNode* dummyNode = new ListNode(-1);
        ListNode* temp = dummyNode;

        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val <= list2->val) {
                temp->next = list1;
                list1 = list1->next;
            } else {
                temp->next = list2;
                list2 = list2->next;
            }
            temp = temp->next;
        }

        // Attach remaining nodes
        if (list1 != nullptr) temp->next = list1;
        else temp->next = list2;

        ListNode* result = dummyNode->next;
        delete dummyNode;
        return result;
    }

    // Finds middle node (used for splitting the list)
    ListNode* findMiddle(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;

        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    // Main merge sort function for linked list
    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;

        ListNode* middle = findMiddle(head);
        ListNode* right = middle->next;
        middle->next = nullptr;
        ListNode* left = head;

        left = sortList(left);
        right = sortList(right);

        return mergeTwoSortedLinkedLists(left, right);
    }
};

// ============================================================================
// 🧪 Main Function for Local Testing
// ============================================================================
int main() {
    // Create Linked List: 4 -> 2 -> 1 -> 3
    ListNode* head = new ListNode(4);
    head->next = new ListNode(2);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(3);

    Solution sol;
    ListNode* result = sol.sortList(head);

    cout << "Sorted Linked List: ";
    while (result) {
        cout << result->val;
        if (result->next) cout << " -> ";
        result = result->next;
    }
    cout << endl;

    // ✅ Expected Output: 1 -> 2 -> 3 -> 4
    return 0;
}
