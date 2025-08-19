/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    // Node* dfs(Node* node, unordered_map<Node*, Node*>& graph2clone) {
    //     if (!node) return nullptr;
    //     if (graph2clone.count(node)) {
    //         return graph2clone[node];
    //     }

    //     Node* curr = new Node(node->val);
    //     graph2clone[node] = curr;

    //     for (Node* nei: node->neighbors) {
    //         Node* nei_clone = dfs(nei, graph2clone);
    //         curr->neighbors.push_back(nei_clone);
    //     }

    //     return curr;
    // }

    // Node* cloneGraph(Node* node) {
    //     unordered_map<Node*, Node*> graph2clone;
    //     return dfs(node, graph2clone);
    // }

    // BFS
    // Time: O(V + E)
    //  - V (# nodes): each node is copied once
    //  - E (# edges): if we pop a node, we loop all of its neighbors. so each edge is processed twice.
    // Space: O(V). including hash map and queue

    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;
        
        unordered_map<Node*, Node*> clones;
        queue<Node*> q;

        clones[node] = new Node(node->val);
        q.push(node);

        while (!q.empty()) {
            int n = q.size();

            for (int i = 0; i < n; i++) {
                Node* curr = q.front();
                q.pop();

                for (Node* nei: curr->neighbors) {
                    if (!clones.count(nei)) {
                        clones[nei] = new Node(nei->val);
                        q.push(nei);
                    }
                    clones[curr]->neighbors.push_back(clones[nei]);
                }
            }
        }

        return clones[node];
    }
};
