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
    ListNode* deleteMiddle(ListNode* head) {
        if (!head || !head->next) return nullptr;
        
        ListNode *curr = head;    
        int n = 1;
        while (curr->next) {
            curr = curr->next;
            n++;
        }
        int mid = n / 2;

        curr = head;
        for (int i = 0; i < mid - 1; i++) {
            curr = curr->next;
        }
        curr->next = curr->next->next;
        return head;
    }
};