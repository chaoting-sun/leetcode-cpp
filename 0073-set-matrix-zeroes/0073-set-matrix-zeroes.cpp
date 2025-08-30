class Solution {
public:
    // Approach: hashtable
    // record the rows and cols that are to be changed to 0
    // Time: O(mn)
    // Space: (m + n)

    // void setZeroes(vector<vector<int>>& matrix) {
    //     int m = matrix.size();
    //     int n = matrix[0].size();

    //     unordered_set<int> rows, cols;
    //     for (int i = 0; i < m; i++) {
    //         for (int j = 0; j < n; j++) {
    //             if (matrix[i][j] == 0) {
    //                 rows.insert(i);
    //                 cols.insert(j);
    //             }
    //         }
    //     }

    //     for (int i = 0; i < m; i++) {
    //         for (int j = 0; j < n; j++) {
    //             if (rows.count(i) || cols.count(j)) {
    //                 matrix[i][j] = 0;
    //             }
    //         }
    //     }
    // }

    // Approach: use in-place flag in first row and firt col to indicate if that row/col is to be changed to 0
    // Time: O(mn)
    // Space: (1)

    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        bool is_row = false, is_col = false;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;

                    if (i == 0) is_row = true;
                    if (j == 0) is_col = true;
                }
            }
        }

        for (int i = 1; i < m; i++) {
            if (matrix[i][0] == 0) {
                for (int j = 1; j < n; j++) {
                    matrix[i][j] = 0;
                }

            }
        }

        for (int j = 1; j < n; j++) {
            if (matrix[0][j] == 0) {
                for (int i = 1; i < m; i++) {
                    matrix[i][j] = 0;
                }
            }
        }

        if (is_row) for (int j = 0; j < n; j++) matrix[0][j] = 0;
        if (is_col) for (int i = 0; i < m; i++) matrix[i][0] = 0;
    }
};