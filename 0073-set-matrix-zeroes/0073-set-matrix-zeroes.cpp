class Solution {
public:
    // Approach: hashtable
    // record the rows and cols that are to be changed to 0
    // Time: O(mn)

    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        unordered_set<int> rows, cols;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    rows.insert(i);
                    cols.insert(j);
                }
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (rows.count(i) || cols.count(j)) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};