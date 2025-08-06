class Solution {
public:
    // Approach: binary search on the first column to get the row and then binary search on the row to find the value
    // Time: O(log(n*m))
    // Space: O(1)

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();

        if (target < matrix[0][0] || target > matrix[n - 1][m - 1]) return false;

        int top = 0, bottom = n - 1;
        while (top + 1 < bottom) {
            int mid = (top + bottom) / 2;
            if (matrix[mid][0] >= target) {
                bottom = mid;
            } else if (matrix[mid][0] < target) {
                top = mid;
            }
        }

        int row = target >= matrix[bottom][0] ? bottom : top;

        int left = 0, right = m - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (matrix[row][mid] > target) {
                right = mid - 1;
            } else if (matrix[row][mid] < target) {
                left = mid + 1;
            } else {
                return true;
            }
        }

        return false;
    }
};