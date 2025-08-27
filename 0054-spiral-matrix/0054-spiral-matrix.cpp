class Solution {
public:
    // Approach1

    // void recordOneCircle(vector<vector<int>>& matrix, int step, vector<int>& ans) {
    //     int m = matrix.size();
    //     int n = matrix[0].size();
        
    //     ans.push_back(matrix[step][step]);
        
    //     for (int j = step + 1; j <= n - step - 1; j++) {
    //         int row = step;
    //         ans.push_back(matrix[row][j]);
    //     }
        
    //     for (int i = step + 1; i <= m - step - 1; i++) {
    //         int col = n - step - 1;
    //         ans.push_back(matrix[i][col]);
    //     }
        
    //     if (step < m - step - 1) {
    //         for (int j = n - step - 2; j >= step; j--) {
    //             int row = m - step - 1;
    //             ans.push_back(matrix[row][j]);
    //         }
    //     }

    //     if (step < n - step - 1) {
    //         for (int i = m - step - 2; i >= step + 1; i--) {
    //             int col = step;
    //             ans.push_back(matrix[i][col]);
    //         }
    //     }
    // }

    // vector<int> spiralOrder(vector<vector<int>>& matrix) {
    //     int m = matrix.size();
    //     int n = matrix[0].size();
    //     int min_side = min(m, n);

    //     vector<int> ans;
    //     int step = 0;

    //     while (min_side - step*2 > 0) {
    //         recordOneCircle(matrix, step, ans);
    //         step++;
    //     }
        
    //     return ans;
    // }

    // Approach2: set boundary

    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int top = 0, bottom = m - 1, left = 0, right = n - 1;

        vector<int> ans;

        while (top <= bottom && left <= right) {
            for (int j = left; j <= right; j++) {
                ans.push_back(matrix[top][j]);
            }
            top++;
            for (int i = top; i <= bottom; i++) {
                ans.push_back(matrix[i][right]);
            }
            right--;
            if (bottom >= top) {
                for (int j = right; j >= left; j--) {
                    ans.push_back(matrix[bottom][j]);
                }
                bottom--;
            }
            if (left <= right) {
                for (int i = bottom; i >= top; i--) {
                    ans.push_back(matrix[i][left]);
                }
                left++;
            }
        }

        return ans;
    }
};