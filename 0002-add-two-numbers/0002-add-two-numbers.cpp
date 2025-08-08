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
    // Approach: Two Pointers
    // Time: O(n+m). n, m = length of l1, l2
    // Space: O(1)

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* curr1 = l1;
        ListNode* curr2 = l2;
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;

        bool addOne = false;

        while (curr1 || curr2) {
            int total_sum = addOne ? 1 : 0;
            // reset
            addOne = false;

            if (curr1) {
                total_sum += curr1->val;
                curr1 = curr1->next;
            }
            if (curr2) {
                total_sum += curr2->val;
                curr2 = curr2->next;
            }

            if (total_sum >= 10) {
                addOne = true;
                total_sum -= 10;
            }

            ListNode* tmp = new ListNode(total_sum);
            curr->next = tmp;
            curr = curr->next;
        }

        if (addOne) {
            ListNode* last = new ListNode(1);
            curr->next = last;
        }

        return dummy->next;
    }
};