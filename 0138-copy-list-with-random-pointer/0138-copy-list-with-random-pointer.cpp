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

// class Solution {
// public:
//     Node* copyRandomList(Node* head) {
//         unordered_map<Node*, Node*> mp;

//         Node* curr = head;

//         while (curr) {
//             // handle the current node
//             if (!mp.count(curr)) {
//                 mp[curr] = new Node(curr->val);
//             }
//             Node* copy = mp[curr];

//             // handle the next node
//             if (curr->next) {
//                 if (!mp.count(curr->next)) {
//                     mp[curr->next] = new Node(curr->next->val);
//                 }
//                 copy->next = mp[curr->next];                
//             }
//             // handle the random node
//             if (curr->random) {
//                 if (!mp.count(curr->random)) {
//                     mp[curr->random] = new Node(curr->random->val);
//                 }
//                 copy->random = mp[curr->random];
//             }

//             curr = curr->next;
//         }
        
//         return mp[head];
//     }
// };

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

// class Solution {
// public:
//     Node* copyRandomList(Node* head) {
//         unordered_map<Node*, Node*> mp;

//         Node* curr = head;

//         while (curr) {
//             // handle the current node
//             if (!mp.count(curr)) {
//                 mp[curr] = new Node(curr->val);
//             }
//             Node* copy = mp[curr];

//             // handle the next node
//             if (curr->next) {
//                 if (!mp.count(curr->next)) {
//                     mp[curr->next] = new Node(curr->next->val);
//                 }
//                 copy->next = mp[curr->next];                
//             }
//             // handle the random node
//             if (curr->random) {
//                 if (!mp.count(curr->random)) {
//                     mp[curr->random] = new Node(curr->random->val);
//                 }
//                 copy->random = mp[curr->random];
//             }

//             curr = curr->next;
//         }
        
//         return mp[head];
//     }
// };

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;        

        // create copy and link copy->next
        Node* curr = head;
        while (curr) {
            Node* copy = new Node(curr->val);
            copy->next = curr->next;
            curr->next = copy;

            curr = copy->next;
        }

        // link copy->random
        curr = head;
        while (curr) {
            Node* copy = curr->next;
            copy->random = curr->random ? curr->random->next : nullptr;

            curr = curr->next->next;
        }

        // split the original linked list and the copy
        Node* copy_head = head->next;
        curr = head;
        while (curr) {
            Node* copy = curr->next;
            curr->next = copy->next;
            copy->next = copy->next ? copy->next->next : nullptr;

            curr = curr->next;
            copy = copy->next;
        }

        return copy_head;
    }
};

// test case:
// ll: 1 -> 2 -> 3
// random: 1->1, 2->null, 3->2

// trace:
// curr = node1
// copy1, copy1->next = node2, node1->next = copy1
// ll: node1 -> copy1 -> node2 -> node3
// curr = node2
// ll: node1 -> copy1 -> node2 -> copy2 -> node3
// curr = node3
// ll: node1 -> copy1 -> node2 -> copy2 -> node3 -> copy3

// curr = node1
// copy1->random = copy1
// curr = node2
// copy2->random = nullptr
// curr = node3
// copy3->random = copy2

// ll: node1 -> copy1 -> node2 -> copy2 -> node3 -> copy3
//                                          curr     copy