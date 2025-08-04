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
    // Approach: store the node references in the array, and then link the nodes by their array index
    // Time: O(n)
    // Space: O(n)

    void reorderList(ListNode* head) {
        vector<ListNode*> nodes;
        ListNode* curr = head;
        while (curr) {
            nodes.push_back(curr);
            curr = curr->next;
        }

        int start = 0, end = nodes.size() - 1;
        while (start <= end) {
            // handle cases of odd number of nodes
            if (start == end) {
                nodes[start]->next = nullptr;
                break;
            }
            // handle cases of even number of nodes
            if (start + 1 == end) {
                nodes[start]->next = nodes[end];
                nodes[end]->next = nullptr;
                break;
            }
            
            nodes[start]->next = nodes[end];
            nodes[end]->next = nodes[start + 1];

            start++;
            end--;
        }
    }
};