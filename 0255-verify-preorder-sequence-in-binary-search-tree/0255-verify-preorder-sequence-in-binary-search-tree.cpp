class Solution {
public:
    bool check(vector<int>& preorder, int left, int right) {
        if (left >= right) return true;
        int head = preorder[left];
        int left_subtree_max = -1, right_subtree_min = -1;
        for (int i = left + 1; i <= right; i++) {
            if (preorder[i] < head) {
                left_subtree_max = i;
            } else {
                if (right_subtree_min == -1) right_subtree_min = i;
            }
        }
        if (left_subtree_max != -1 && right_subtree_min != -1) {
            if (right_subtree_min < left_subtree_max) return false;
            return check(preorder, left, left_subtree_max) && check(preorder, right_subtree_min, right);
        } else if (left_subtree_max == -1 || right_subtree_min == -1) {
            return check(preorder, left + 1, right);
        } else {
            return true;
        }
    }

    bool verifyPreorder(vector<int>& preorder) {
        int n = preorder.size();
        if (n == 0) return true;
        return check(preorder, 0, n - 1);
    }
};
