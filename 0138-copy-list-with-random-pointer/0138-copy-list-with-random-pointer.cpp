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
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> mp;

        Node* curr = head;
        Node* dummy_copy = new Node(0);
        Node* curr_copy = dummy_copy;

        while (curr) {
            // handle the current node
            if (!mp.count(curr)) {
                mp[curr] = new Node(curr->val);
            }
            Node* copy = mp[curr];

            // handle the next node
            if (curr->next) {
                if (!mp.count(curr->next)) {
                    mp[curr->next] = new Node(curr->next->val);
                }
                copy->next = mp[curr->next];                
            }
            // handle the random node
            if (curr->random) {
                if (!mp.count(curr->random)) {
                    mp[curr->random] = new Node(curr->random->val);
                }
                copy->random = mp[curr->random];
            }

            curr = curr->next;

            curr_copy->next = copy;
            curr_copy = copy;
        }
        
        return dummy_copy->next;
    }
};

// test case:
// next: 1 -> 2 -> 3
// random: 1->1, 2->null, 3->2
// trace:
// dummy - node copy 1 - node copy 2 - node copy 3 (curr_copy)
// mp = { node 1: node copy 1 (node copy 2, node copy 1), node 2: node copy 2 (node copy 3, null), node 3: node copy 3 (null, null) }
// curr = node 1
// copy = node copy 1 (null, null)
// copy = node copy 1 (node copy 2, null)
// copy = node copy 1 (node copy 2, node copy 1)
// curr = node 2
// copy = node copy 2 (node copy 3, null)
// curr = node 3

// keep track of the mapping of node -> copy
// iterate the linked list from the head, construct the copy of the next node and random node, storing
// them in the hash map. If the hash map has stored the next or random node, then directly use it.