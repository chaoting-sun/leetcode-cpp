/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Codec {
public:
    void preorderEncode(TreeNode* root, string& code) {
        if (!root) {
            code += "#,";
            return;
        }
        
        code += to_string(root->val) + ",";
        preorderEncode(root->left, code);
        preorderEncode(root->right, code);
    };

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string code = "";
        preorderEncode(root, code);
        return code;
    }

    TreeNode* preorderDecode(vector<string>& code_vec, int& idx) {
        if (code_vec[idx] == "#") {
            idx++;
            return nullptr;
        }

        TreeNode* curr = new TreeNode(stoi(code_vec[idx]));
        idx++;
        
        curr->left = preorderDecode(code_vec, idx);
        curr->right = preorderDecode(code_vec, idx);
        return curr;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> code_vec;
        int start = 0, end = 0;
        while (start < data.size()) {
            while (end < data.size() && data[end] != ',') end++;
            code_vec.push_back(data.substr(start, end - start));
            start = end + 1;
            end = start;
        }

        int idx = 0;
        return preorderDecode(code_vec, idx);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));