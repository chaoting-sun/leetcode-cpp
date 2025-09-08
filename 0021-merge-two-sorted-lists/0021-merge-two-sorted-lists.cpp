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
    // Approach1: Iteration
    // Time: O(n+m), where n, m are the length of list1 and list2
    // Space: O(1)

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *ptr1 = list1, *ptr2 = list2;
        ListNode *dummy = new ListNode();
        ListNode *curr = dummy;

        while (ptr1 || ptr2) {
            if (!ptr1) {
                curr->next = ptr2;
                break;
            } else if (!ptr2) {
                curr->next = ptr1;
                break;
            } else {
                if (ptr1->val < ptr2->val) {
                    curr->next = ptr1;
                    ptr1 = ptr1->next;
                } else {
                    curr->next = ptr2;
                    ptr2 = ptr2->next;
                }
                curr = curr->next;
            }
        }

        return dummy->next;
    }

    // Approach2: Recursion
    // Time: O(n+m)
    // Space: O(n+m)

    // ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    //     if (!list1)
    //         return list2;
    //     if (!list2)
    //         return list1;

    //     if (list1->val < list2->val) {
    //         list1->next = mergeTwoLists(list1->next, list2);
    //         return list1;
    //     } else {
    //         list2->next = mergeTwoLists(list1, list2->next);
    //         return list2;
    //     }
    // }
};