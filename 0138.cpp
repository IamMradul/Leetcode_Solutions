/*
====================================================
Author: Mradul Gupta
GitHub Username: IamMradul
GitHub Profile: https://github.com/IamMradul
LeetCode Username: Mradul_mg
LeetCode Profile: https://leetcode.com/u/Mradul_mg/

LeetCode Problem: 138. Copy List with Random Pointer
Problem Link: https://leetcode.com/problems/copy-list-with-random-pointer/

Time Complexity: O(n)
Space Complexity: O(1)  (excluding output list)
====================================================
*/

#include <bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};

// ==================== LeetCode Solution ====================
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;

        // 1️⃣ Insert copied nodes in between original nodes
        Node* curr = head;
        while (curr) {
            Node* copy = new Node(curr->val);
            copy->next = curr->next;
            curr->next = copy;
            curr = copy->next;
        }

        // 2️⃣ Assign random pointers for copied nodes
        curr = head;
        while (curr) {
            if (curr->random)
                curr->next->random = curr->random->next;
            curr = curr->next->next;
        }

        // 3️⃣ Separate original and copied lists
        Node* dummy = new Node(0);
        Node* copyCurr = dummy;
        curr = head;

        while (curr) {
            Node* copy = curr->next;
            curr->next = copy->next;   // restore original list
            copyCurr->next = copy;     // build copied list
            copyCurr = copy;
            curr = curr->next;
        }

        return dummy->next;
    }
};

// ==================== Local Testing ====================
int main() {
    /*
        Sample Test Case:
        Input:
        [ [1, random->3], [2, random->1], [3, random->null] ]

        Expected Output:
        Deep copied list with same structure but different memory references
    */

    // Creating original list: 1 -> 2 -> 3
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);

    n1->next = n2;
    n2->next = n3;

    n1->random = n3;  // 1 -> 3
    n2->random = n1;  // 2 -> 1
    n3->random = nullptr;

    Solution sol;
    Node* copiedHead = sol.copyRandomList(n1);

    // Print copied list (value and random value)
    cout << "Copied List:\n";
    Node* temp = copiedHead;
    while (temp) {
        cout << "Node val = " << temp->val << ", Random = ";
        if (temp->random)
            cout << temp->random->val << "\n";
        else
            cout << "NULL\n";
        temp = temp->next;
    }

    return 0;
}
