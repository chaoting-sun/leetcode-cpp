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
    void buildAdj(vector<TreeNode*>& adj, TreeNode* root, TreeNode* parent) {
        if (!root) return;
        adj[root->val] = parent;
        buildAdj(adj, root->left, root);
        buildAdj(adj, root->right, root);
    }

    void getDistanceKNodes(const vector<TreeNode*>& adj, TreeNode* curr, TreeNode* prev, vector<int>& ans, int dist, int k) {
        if (!curr) return;
        
        if (dist == k) {
            ans.push_back(curr->val);
        }
        
        if (adj[curr->val] && prev != adj[curr->val]) {
            getDistanceKNodes(adj, adj[curr->val], curr, ans, dist + 1, k);
        }

        if (prev != curr->left) {
            getDistanceKNodes(adj, curr->left, curr, ans, dist + 1, k);
        }
        if (prev != curr->right) {
            getDistanceKNodes(adj, curr->right, curr, ans, dist + 1, k);
        }
    }

public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        int MAX_VAL = 500;
        vector<TreeNode*> adj(MAX_VAL + 1, nullptr);
        buildAdj(adj, root, nullptr);

        vector<int> ans;
        getDistanceKNodes(adj, target, target, ans, 0, k);
        return ans;
    }
};

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