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
    Node* dfs(Node* node, unordered_map<Node*, Node*>& graph2clone) {
        if (!node) return nullptr;
        if (graph2clone.count(node)) {
            return graph2clone[node];
        }

        Node* curr = new Node(node->val);
        graph2clone[node] = curr;

        for (Node* nei: node->neighbors) {
            Node* nei_clone = dfs(nei, graph2clone);
            curr->neighbors.push_back(nei_clone);
        }

        return curr;
    }

    Node* cloneGraph(Node* node) {
        unordered_map<Node*, Node*> graph2clone;
        return dfs(node, graph2clone);
    }
};