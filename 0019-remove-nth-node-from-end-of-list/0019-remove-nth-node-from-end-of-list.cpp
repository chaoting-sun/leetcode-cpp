/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* curr = head;
        int sz = 0;
        while (curr) {
            sz++;
            curr = curr->next;
        }

        ListNode* dummy = new ListNode(0, head);
        curr = dummy;
        int n_move = sz - n;
        while (n_move--) curr = curr->next;

        if (curr->next->next) {
            curr->next = curr->next->next;
        } else {
            curr->next = nullptr;
        }
        return dummy->next;
    }
};