// Approach: Monotonic Stack
// Time: O(n)
// Space: O(n)

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

// class Solution {
// public:
//     vector<int> nextLargerNodes(ListNode* head) {
//         vector<int> values;
//         ListNode* curr = head;
//         while (curr) {
//             values.push_back(curr->val);
//             curr = curr->next;
//         }
//         int n = values.size();
//         vector<int> ans(n);
//         stack<int> stk; // monotonic increasing
//         for (int i = n - 1; i >= 0; i--) {
//             while (!stk.empty() && values[i] >= values[stk.top()]) {
//                 stk.pop();
//             }
//             if (!stk.empty()) ans[i] = values[stk.top()];
//             stk.push(i);
//         }
//         return ans;
//     }
// };

class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        ListNode* curr = head;
        stack<pair<int,int>> stk; // idx, value
        vector<int> ans;
        while (curr) {
            ans.push_back(0);
            while (!stk.empty() && stk.top().second < curr->val) {
                auto [idx, _] = stk.top();
                ans[idx] = curr->val;
                stk.pop();
            }
            stk.push({ ans.size() - 1, curr->val });
            curr = curr->next;
        }
        return ans;
    }
};
