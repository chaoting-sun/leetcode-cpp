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
    ListNode* reverseKGroup(ListNode* head, int k) {
        vector<ListNode*> nodes;
        ListNode* curr = head;
        while (curr) {
            nodes.push_back(curr);
            curr = curr->next;
        }

        int n = nodes.size();

        ListNode* dummy = new ListNode(0);
        curr = dummy;
        int curr_start = 0;

        for (int i = k - 1; i < n; i += k) {
            curr_start = i;
            for (int j = 0; j < k; j++) {
                int idx = i - j;
                curr->next = nodes[idx];
                curr = curr->next;
            }
        }
        if (curr_start < n - 1) {
            curr->next = nodes[curr_start + 1];
        } else {
            curr->next = nullptr;
        }

        return dummy->next;
    }
};