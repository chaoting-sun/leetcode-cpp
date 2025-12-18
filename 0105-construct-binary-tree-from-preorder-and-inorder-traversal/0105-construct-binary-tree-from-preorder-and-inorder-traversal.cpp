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
class Solution {
public:
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
     		int n = preorder.size();
		unordered_map<int,int> inorder_val_to_idx;
		for (int i = 0; i < n; i++) inorder_val_to_idx[inorder[i]] = i;

		auto deserialize = [&](auto&& self, int preorder_start, int inorder_start, int size) -> TreeNode* {
	if (size <= 0) return nullptr;

int root_val = preorder[preorder_start];
int inorder_root_idx = inorder_val_to_idx[root_val];
int left_subtree_size = inorder_root_idx - inorder_start;

TreeNode* node = new TreeNode(root_val);
node->left = self(self, preorder_start + 1, inorder_start, left_subtree_size);
node->right = self(self, preorder_start + left_subtree_size + 1, inorder_root_idx + 1, size - 1 - left_subtree_size);
return node;
};

		return deserialize(deserialize, 0, 0, n);
}
};
