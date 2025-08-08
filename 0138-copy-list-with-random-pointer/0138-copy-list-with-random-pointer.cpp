/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

// Approach1: Array + Hash Table
// Time: O(n)
// Space: O(n)

// class Solution {
// public:
//     Node* copyRandomList(Node* head) {
//         if (!head) return nullptr;

//         int n = 0;
//         vector<Node*> nodes;

//         // count the nodes and maintain array (index -> reference)
//         Node* curr = head;
//         while (curr) {
//             nodes.push_back(curr);
//             n++;
//             curr = curr->next;
//         }
        
//         // maintain node reference -> index
//         unordered_map<Node*, int> node_ids;
//         for (int i = 0; i < n; i++) {
//             node_ids[nodes[i]] = i;
//         }

//         // construct the copy
//         // 1. handle val
//         vector<Node*> new_nodes;
//         for (int i = 0; i < n; i++) {
//             Node* node_copy = new Node(nodes[i]->val);
//             new_nodes.push_back(node_copy);
//         }
//         // 2. handle next & random
//         for (int i = 0; i < n; i++) {
//             if (i < n - 1) {
//                 new_nodes[i]->next = new_nodes[i + 1];
//             }
//             int random_id = nodes[i]->random ? node_ids[nodes[i]->random] : -1;
//             if (random_id != -1) {
//                 new_nodes[i]->random = new_nodes[random_id];
//             }
//         }

//         return new_nodes[0];
//     }
// };

// Approach2: Recursion
// we recursively do:
//  1. copy current node (curr) with a value
//  2. copy curr->next
//  3. copy curr->random

// Time: O(n)
// Space: O(n)

// class Solution {
// private:
//     unordered_map<Node*, Node*> node_map;

// public:
//     Node* copyRandomList(Node* head) {
//         if (!head) return nullptr;

//         if (node_map.find(head) != node_map.end()) {
//             return node_map[head];
//         }
        
//         // copy current node with a value
//         Node* copy = new Node(head->val);

//         // a node may be pointed to by node->random many times
//         // record the node -> copy such that when the node appears twice we can directly use the corresponding copy
//         node_map[head] = copy;
        
//         // copy curr->next
//         copy->next = copyRandomList(head->next);
//         // copy curr->next
//         copy->random = copyRandomList(head->random);
//         return copy;
//     }

// };

// Approach3: Iteration with a map

// Time: O(n)
// Space: O(n)

// class Solution {
// public:
//     Node* copyRandomList(Node* head) {
//         if (!head) return nullptr;
        
//         unordered_map<Node*, Node*> node_map;        
//         Node* dummy = new Node(0);
        
//         Node* curr = head;
//         Node* curr_copy = dummy;

//         while (curr) {
//             Node *new_copy = new Node(curr->val);
//             curr_copy->next = new_copy;
//             node_map[curr] = new_copy;

//             curr_copy = curr_copy->next;
//             curr = curr->next;
//         }
        
//         curr = head;
//         curr_copy = dummy->next;

//         while (curr) {
//             curr_copy->random = node_map[curr->random];
//             curr = curr->next;
//             curr_copy = curr_copy->next;
//         }

//         return dummy->next;
//     }
// };

// Approach4: Iteration with interweaving

// Time: O(n)
// Space: O(1)

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;

        Node* curr = head;

        // A->B->C ==> A->A'->B->B'->C->C'
        while (curr) {
            Node* tmp = new Node(curr->val);
            tmp->next = curr->next;
            curr->next = tmp;
            curr = tmp->next;
        }

        curr = head;

        while (curr) {
            if (curr->random) curr->next->random = curr->random->next;
            curr = curr->next->next;
        }

        // A->A'->B->B'->C->C' => A->B->C and A'->B'->C'
        curr = head;
        Node* head_copy = head->next;
        Node* curr_copy = head_copy;

        while (curr) {
            curr->next = curr_copy->next;
            if (curr_copy->next) {
                curr_copy->next = curr_copy->next->next;
                curr_copy = curr_copy->next;
            }
            curr = curr->next;
        }
        return head_copy;
    }
};