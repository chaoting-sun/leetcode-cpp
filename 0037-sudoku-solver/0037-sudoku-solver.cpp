class Solution {
public:
    bool isValid(vector<vector<char>>& board, int i, int j, int c) {
        // row
        for (int k = 0; k < 9; k++) {
            if (board[i][k] == c) return false;
        }
        // col
        for (int k = 0; k < 9; k++) {
            if (board[k][j] == c) return false;
        }
        int x = i / 3 * 3, y = j / 3 * 3;
        for (int p = 0; p < 3; p++) {
            for (int q = 0; q < 3; q++) {
                if (board[x + p][y + q] == c) return false;
            }
        }
        return true;
    }

    bool backtrack(vector<vector<char>>& board, int i, int j) {
        if (i == 9) return true;
        if (j == 9) return backtrack(board, i + 1, 0);
        
        // move to the next cell if the current one has been solved
        if (board[i][j] != '.') return backtrack(board, i, j + 1);

        for (char c = '1'; c <= '9'; c++) {
            if (!isValid(board, i, j, c)) continue;
            board[i][j] = c;
            if (backtrack(board, i, j + 1)) {
                return true;
            }
            board[i][j] = '.';
        }

        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
        backtrack(board, 0, 0);
    }
};