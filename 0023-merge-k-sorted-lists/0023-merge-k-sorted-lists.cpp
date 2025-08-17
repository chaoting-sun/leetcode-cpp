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

// Time: O(n*logk). n is the total number of nodes. k is the number of lists

// method1
// struct NodeMin {
//     bool operator()(ListNode* a, ListNode* b) const {
//         return a->val > b->val;
//     }
// };

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // method1
        // priority_queue<ListNode*, vector<ListNode*>, NodeMin> pq;

        // method2 
        auto compare = [](ListNode* a, ListNode* b) {
            return a->val > b->val;
        };
        priority_queue<ListNode*, vector<ListNode*>, decltype(compare)> pq;

        for (int i = 0; i < lists.size(); i++) {
            if (lists[i]) {
                pq.push(lists[i]);
            }
        }

        ListNode* head = new ListNode(0);
        ListNode* prev = head;

        while (!pq.empty()) {
            ListNode* curr = pq.top();
            pq.pop();
            prev->next = curr;
            
            if (curr->next) {
                pq.push(curr->next);
            }

            prev = prev->next;
        }

        return head->next;
    }
};