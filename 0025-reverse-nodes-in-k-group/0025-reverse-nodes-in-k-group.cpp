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
    // Approach: Array
    // Time: O(N)
    // Space: O(N)

    // ListNode* reverseKGroup(ListNode* head, int k) {
    //     vector<ListNode*> nodes;
    //     ListNode* curr = head;
    //     while (curr) {
    //         nodes.push_back(curr);
    //         curr = curr->next;
    //     }

    //     int n = nodes.size();

    //     ListNode* dummy = new ListNode(0);
    //     curr = dummy;
    //     int curr_start = 0;

    //     for (int i = k - 1; i < n; i += k) {
    //         curr_start = i;
    //         for (int j = 0; j < k; j++) {
    //             int idx = i - j;
    //             curr->next = nodes[idx];
    //             curr = curr->next;
    //         }
    //     }
    //     if (curr_start < n - 1) {
    //         curr->next = nodes[curr_start + 1];
    //     } else {
    //         curr->next = nullptr;
    //     }

    //     return dummy->next;
    // }

    // Approach: Direct Modification
    // Time: O(N)
    // Space: O(1)
    
    // reverse [head, stop) and return { new_head, new_tail }
    pair<ListNode*, ListNode*> reverseOneGroup(ListNode* head, ListNode* stop) {
        ListNode* prev = stop;
        ListNode* curr = head;

        while (curr != stop) {
            ListNode *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return { prev, head };
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k <= 1 || !head) return head;
        
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* group_prev = dummy;

        while (true) {
            ListNode* kth = group_prev;
            for (int i = 0; i < k && kth; i++) kth = kth->next;
            if (!kth) break;

            ListNode* group_start = group_prev->next;
            ListNode* group_next = kth->next;

            auto [new_head, new_tail] = reverseOneGroup(group_start, group_next);
            group_prev->next = new_head;
            group_prev = new_tail;
        }

        return dummy->next;
    }
};