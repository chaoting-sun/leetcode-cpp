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
    // Approach1: Hash Table. Go through each node and store the reference in the set.
    // If no cycle exists, then we'll reach null. if the cycle exists, then we'll find
    // the node that has been stored in the set.
    // Time: O(n)
    // Space: O(n)

    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> set;
        ListNode* curr = head;
        while (curr) {
            if (set.count(curr)) {
                return true;
            }
            set.insert(curr);
            curr = curr->next;
        }
        return false;
    }

    // Approach: Fast & Slow. Intialize two pointers fast and slow that point to head,
    // then for each run, move fast two step and slow one step. If the listed list has
    // cycle, then fast will cross from the last node to the previous one and meet the
    // slow node in somewhere.

    // bool hasCycle(ListNode *head) {
    //     if (!head || !head->next) return false;
    //     ListNode *slow = head, *fast = head;

    //     while (fast && slow) {
    //         if (!fast->next) return false;

    //         slow = slow->next;
    //         fast = fast->next->next;

    //         if (slow == fast) return true;
    //     }

    //     return false;
    // }
};