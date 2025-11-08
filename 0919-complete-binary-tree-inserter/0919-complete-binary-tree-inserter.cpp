/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class CBTInserter {
public:
    TreeNode* root;
    queue<TreeNode*> candidates;

    CBTInserter(TreeNode* root) {
        this->root = root;
    
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                TreeNode* node = q.front();
                q.pop();
                if (!node->left || !node->right) candidates.push(node);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }
    }
    
    int insert(int val) {
        TreeNode* node = new TreeNode(val);
        TreeNode* parent = candidates.front();
        if (!parent->left) {
            parent->left = node;
        } else {
            parent->right = node;
            candidates.pop();
        }
        candidates.push(node);
        return parent->val;
    }
    
    TreeNode* get_root() {
        return root;
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(val);
 * TreeNode* param_2 = obj->get_root();
 */