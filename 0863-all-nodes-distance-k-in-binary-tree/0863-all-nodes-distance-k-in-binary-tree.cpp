/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
private:
    void buildParentMap(vector<TreeNode*>& adj, TreeNode* root, TreeNode* parent) {
        if (!root) return;
        adj[root->val] = parent;
        buildParentMap(adj, root->left, root);
        buildParentMap(adj, root->right, root);
    }

public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        int MAX_VAL = 500;
        vector<TreeNode*> parent_map(MAX_VAL + 1, nullptr);
        buildParentMap(parent_map, root, nullptr);

        queue<TreeNode*> node_queue;
        vector<bool> visited(MAX_VAL + 1, false);

        node_queue.push(target);
        visited[target->val] = true;

        int distance = 0;
        
        // bfs layer by layer
        while (!node_queue.empty()) {
            if (distance == k) {
                vector<int> result;
                while (!node_queue.empty()) {
                    result.push_back(node_queue.front()->val);
                    node_queue.pop();
                }
                return result;
            }

            int size = node_queue.size();
            for (int i = 0; i < size; i++) {
                TreeNode* curr = node_queue.front();
                node_queue.pop();

                vector<TreeNode*> neighbors = { curr->left, curr->right, parent_map[curr->val] };
                for (auto neighbor: neighbors) {
                    if (neighbor && !visited[neighbor->val]) {
                        node_queue.push(neighbor);
                        visited[neighbor->val] = true;
                    }
                }
            }
            distance++;
        }

        return {};
    }
};

// 沒弄清楚所求範圍：這題 k 可以是 0，所以答案可以包含

// class Solution {
// private:
//     void buildParentMap(vector<TreeNode*>& adj, TreeNode* root, TreeNode* parent) {
//         if (!root) return;
//         adj[root->val] = parent;
//         buildParentMap(adj, root->left, root);
//         buildParentMap(adj, root->right, root);
//     }

//     void getDistanceKNodes(const vector<TreeNode*>& parent_map, TreeNode* curr, TreeNode* prev, vector<int>& ans, int dist, int k) {
//         if (!curr) return;
        
//         if (dist == k) {
//             ans.push_back(curr->val);
//         }
        
//         TreeNode* parent = parent_map[curr->val];
//         if (parent && prev != parent) {
//             getDistanceKNodes(parent_map, parent, curr, ans, dist + 1, k);
//         }

//         if (curr->left && prev != curr->left) {
//             getDistanceKNodes(parent_map, curr->left, curr, ans, dist + 1, k);
//         }
//         if (curr->right && prev != curr->right) {
//             getDistanceKNodes(parent_map, curr->right, curr, ans, dist + 1, k);
//         }
//     }

// public:
//     vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
//         int MAX_VAL = 500;
//         vector<TreeNode*> parent_map(MAX_VAL + 1, nullptr);
//         buildParentMap(parent_map, root, nullptr);

//         vector<int> ans;
//         getDistanceKNodes(parent_map, target, target, ans, 0, k);
//         return ans;
//     }
// };

// Submit Error:
// if (adj[curr] && prev != adj[curr]) {
// to
// if (adj[curr->val] && prev != adj[curr->val]) {

// getDistanceKNodes(adj, adj[curr], curr, ans, dist + 1, k);
// to
// getDistanceKNodes(adj, adj[curr->val], curr, ans, dist + 1, k);

// no return
// to
// return ans;

// if (!root || !parent) return;
// to
// if (!root) return;