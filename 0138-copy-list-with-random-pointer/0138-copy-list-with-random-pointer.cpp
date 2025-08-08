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

class Solution {
public:
    // Approach1: Array + Hash Table
    // Time: O(n)
    // Space: O(n)

    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;

        int n = 0;
        vector<Node*> nodes;

        // count the nodes and maintain array (index -> reference)
        Node* curr = head;
        while (curr) {
            nodes.push_back(curr);
            n++;
            curr = curr->next;
        }
        
        // maintain node reference -> index
        unordered_map<Node*, int> node_ids;
        for (int i = 0; i < n; i++) {
            node_ids[nodes[i]] = i;
        }

        // construct the copy
        // 1. handle val
        vector<Node*> new_nodes;
        for (int i = 0; i < n; i++) {
            Node* node_copy = new Node(nodes[i]->val);
            new_nodes.push_back(node_copy);
        }
        // 1. handle next & random
        for (int i = 0; i < n; i++) {
            if (i < n - 1) {
                new_nodes[i]->next = new_nodes[i + 1];
            }
            int random_id = nodes[i]->random ? node_ids[nodes[i]->random] : -1;
            if (random_id != -1) {
                new_nodes[i]->random = new_nodes[random_id];
            }
        }

        return new_nodes[0];
    }
};