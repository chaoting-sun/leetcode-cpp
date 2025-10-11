class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        for (int i = 0; i < m; i++) {
            int val = matrix[i][0];
            int k = 1;
            while (i + k < m && k < n) {
                if (matrix[i + k][k] != val) return false;
                k++;
            }
        }

        for (int i = 1; i < n; i++) {
            int val = matrix[0][i];
            int k = 1;
            while (k < m && i + k < n) {
                if (matrix[k][i + k] != val) return false;
                k++;
            }
        }

        return true;
    }
};