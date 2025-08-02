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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1) return list2;
        if (!list2) return list1;
        
        ListNode *curr1 = list1, *curr2 = list2;
        ListNode *head, *tail;

        if (curr1->val < curr2->val) {
            head = curr1;
            tail = curr1;
            curr1 = curr1->next;
        } else {
            head = curr2;
            tail = curr2;
            curr2 = curr2->next;
        }

        while (curr1 || curr2) {
            if (!curr1) {
                tail->next = curr2;
                break;
            }
            if (!curr2) {
                tail->next = curr1;
                break;
            }
            
            if (curr1->val < curr2->val) {
                ListNode* tmp = curr1->next;
                tail->next = curr1;
                curr1 = tmp;
            } else {
                ListNode* tmp = curr2->next;
                tail->next = curr2;
                curr2 = tmp;
            }

            tail = tail->next;
            tail->next = nullptr;
        }

        return head;
    }
};