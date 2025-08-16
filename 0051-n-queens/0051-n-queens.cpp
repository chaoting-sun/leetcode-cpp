class Solution {
public:
    // Approach1: put the queen row by row and check if each position is valid
    // Time: O(n*n!). in 1st row, we can choose from n position. in 2nd row, we at most can
    // choose from n - 2 position, this pattern continues, resulting in an approximate time
    // complexity of n!. for each position, we need O(n) to check the validity.
    // Space: O(n^2)

    // vector<vector<string>> ans;

    // void backtrack(int n, int row, vector<vector<bool>>& is_placed, vector<string>& placement) {
    //     if (row == n) {
    //         ans.push_back(placement);
    //         return;
    //     }

    //     int r, c;
    //     for (int col = 0; col < n; col++) {
    //         int valid = true;
            
    //         r = 0;
    //         while (r < row) {
    //             if (is_placed[r][col]) {
    //                 valid = false;
    //                 break;
    //             }
    //             r++;
    //         }
    //         if (!valid) continue;
            
    //         r = row - 1;
    //         c = col - 1;
    //         while (r >= 0 && c >= 0) {
    //             if (is_placed[r][c]) {
    //                 valid = false;
    //                 break;
    //             }
    //             r--;
    //             c--;
    //         }
    //         if (!valid) continue;

    //         r = row - 1;
    //         c = col + 1;
    //         while (r >= 0 && c < n) {
    //             if (is_placed[r][c]) {
    //                 valid = false;
    //                 break;
    //             }
    //             r--;
    //             c++;
    //         }
    //         if (!valid) continue;

    //         is_placed[row][col] = true;
    //         placement.push_back(string(n, '.').replace(col, 1, "Q"));

    //         backtrack(n, row + 1, is_placed, placement);

    //         is_placed[row][col] = false;
    //         placement.pop_back();
    //     }
    // }

    // vector<vector<string>> solveNQueens(int n) {
    //     vector<vector<bool>> is_placed(n, vector<bool>(n, false));
    //     vector<string> placement;

    //     backtrack(n, 0, is_placed, placement);
    //     return ans;
    // }

    // Approach2: based on the first approach, we aim to minimize the time to check if a position is valid for each col
    // to check the col: we use colSet to store those cols placed with a queue
    // to check the left-top diagonal, we use posSet to store those col - row
    // to check the right-top diagonal, we use negSet to store those col + row
    // So the validation changes from O(n) to O(1)
    
    // Time: O(n!)
    // Space: O(n)

    vector<vector<string>> ans;
    unordered_set<int> colUsed, posUsed, negUsed;

    vector<string> buildPositionString(vector<int>& positions) {
        vector<string> posString;
        int n = positions.size();
        
        for (int i = 0; i < n; i++) {
            posString.push_back(string(n, '.').replace(positions[i], 1, "Q"));
        }
        return posString;
    }

    void backtrack(int n, int row, vector<string>& placement, vector<int>& positions) {
        if (row == n) {
            ans.push_back(buildPositionString(positions));
            return;
        }
        
        for (int col = 0; col < n; col++) {
            if (colUsed.find(col) != colUsed.end()) continue;
            if (posUsed.find(col - row) != posUsed.end()) continue;
            if (negUsed.find(col + row) != negUsed.end()) continue;

            colUsed.insert(col);
            posUsed.insert(col - row);
            negUsed.insert(col + row);
            positions[row] = col;

            backtrack(n, row + 1, placement, positions);

            colUsed.erase(col);
            posUsed.erase(col - row);
            negUsed.erase(col + row);
            positions[row] = -1;
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> placement;
        vector<int> positions(n, -1);

        backtrack(n, 0, placement, positions);
        return ans;
    }    
};
