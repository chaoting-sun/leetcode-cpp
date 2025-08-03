/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    // Approach: Fast & Slow. Intialize two pointers fast and slow that point to head,
    // then for each run, move fast two step and slow one step. If the listed list has
    // cycle, then fast will cross from the last node to the previous one and meet the
    // slow node in somewhere.

    bool hasCycle(ListNode *head) {
        if (!head || !head->next) return false;
        ListNode *slow = head, *fast = head;

        while (fast && slow) {
            if (!fast->next) return false;

            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) return true;
        }

        return false;
    }
};