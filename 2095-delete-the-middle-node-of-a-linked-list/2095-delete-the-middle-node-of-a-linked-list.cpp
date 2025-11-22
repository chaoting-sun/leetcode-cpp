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
        
        ListNode *dummyHead = new ListNode(0, head);
        ListNode *curr = head;    
        int n = 1;
        while (curr->next) {
            curr = curr->next;
            n++;
        }
        int mid = n / 2;

        curr = dummyHead;
        while (mid--) curr = curr->next;
        curr->next = curr->next->next;
        return head;
    }
};