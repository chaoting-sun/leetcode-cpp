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

        vector<int> ans;

        queue<TreeNode*> node_queue;
        vector<bool> visited(MAX_VAL + 1, false);

        node_queue.push(target);
        visited[target->val] = true;

        int distance = 0;
        
        // bfs layer by layer
        while (!node_queue.empty()) {
            if (distance > k) break;

            int size = node_queue.size();
            for (int i = 0; i < size; i++) {
                TreeNode* curr = node_queue.front();
                node_queue.pop();
                if (distance == k) ans.push_back(curr->val);

                if (curr->left && !visited[curr->left->val]) {
                    node_queue.push(curr->left);
                    visited[curr->left->val] = true;
                }
                if (curr->right && !visited[curr->right->val]) {
                    node_queue.push(curr->right);
                    visited[curr->right->val] = true;
                }
                TreeNode* parent = parent_map[curr->val];
                if (parent && !visited[parent->val]) {
                    node_queue.push(parent);
                    visited[parent->val] = true;
                }
            }
            distance++;
        }

        return ans;
    }
};

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