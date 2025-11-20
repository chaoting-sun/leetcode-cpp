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
class BSTIterator {
public:
    TreeNode* curr;
    stack<TreeNode*> stk;

    BSTIterator(TreeNode* root) {
        curr = root;
    }
    
    int next() {
        if (!hasNext()) return -1;
        TreeNode* node = stk.top();
        stk.pop();
        curr = node->right;
        return node->val;
    }
    
    bool hasNext() {
        while (curr) {
            stk.push(curr);
            curr = curr->left;
        }
        return !stk.empty();
    }
};


/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
