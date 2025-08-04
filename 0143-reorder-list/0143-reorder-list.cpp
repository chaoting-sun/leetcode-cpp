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
    // Approach1: store the node references in the array, and then link the nodes by their array index
    // Time: O(n)
    // Space: O(n)

    // void reorderList(ListNode* head) {
    //     vector<ListNode*> nodes;
    //     ListNode* curr = head;
    //     while (curr) {
    //         nodes.push_back(curr);
    //         curr = curr->next;
    //     }

    //     int start = 0, end = nodes.size() - 1;
    //     while (start <= end) {
    //         // handle cases of odd number of nodes
    //         if (start == end) {
    //             nodes[start]->next = nullptr;
    //             break;
    //         }
    //         // handle cases of even number of nodes
    //         if (start + 1 == end) {
    //             nodes[start]->next = nodes[end];
    //             nodes[end]->next = nullptr;
    //             break;
    //         }
            
    //         nodes[start]->next = nodes[end];
    //         nodes[end]->next = nodes[start + 1];

    //         start++;
    //         end--;
    //     }
    // }

    // Approach2:
    // 1. get the middle node that divides the linked list into two lists with the same length. if the number is odd, then split into n and n - 1.
    // 2. reverse the second list
    // 3. merge the two list
    // Time: O(n)
    // Space: O(1)

    void reorderList(ListNode* head) {
        if (!head) return;

        // find the center node that splits two equally long linked list, or with length difference of 1
        ListNode *fast = head, *slow = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // reverse the second linked list
        ListNode *prev = nullptr, *curr = slow->next;
        slow->next = nullptr;

        while (curr) {
            ListNode *tmp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = tmp;
        }

        // merge two linked list
        ListNode *curr1 = head, *curr2 = prev;
        curr = new ListNode(0);

        while (curr1 || curr2) {
            if (!curr1) {
                curr->next = curr2;
                break;
            }
            if (!curr2) {
                curr->next = curr1;
                break;
            }

            ListNode *tmp1 = curr1->next, *tmp2 = curr2->next;

            curr->next = curr1;
            curr = curr->next;
            curr->next = curr2;
            curr = curr->next;

            curr1 = tmp1;
            curr2 = tmp2;
        }
    }
};