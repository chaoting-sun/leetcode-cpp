class Solution {
public:
    int n = 9;
    int nCells = 81;

    bool backtrack(vector<vector<char>>& board, int index) {
        if (index == nCells) {
            return true;
        }

        int currentX = index / n, currentY = index % n;
        
        if (board[currentX][currentY] != '.') {
            return backtrack(board, index + 1);
        }

        // find candidates

        unordered_set<char> candidates = { '1', '2', '3', '4', '5', '6', '7', '8', '9' };
        for (int x = 0; x < n; x++) {
            if (x != currentX) candidates.erase(board[x][currentY]);
        }
        for (int y = 0; y < n; y++) {
            if (y != currentY) candidates.erase(board[currentX][y]);
        }
        int startX = (currentX / 3) * 3, startY = (currentY / 3) * 3;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                int x = startX + i;
                int y = startY + j;
                if (x != currentX || y != currentY) candidates.erase(board[x][y]);
            }
        }

        if (candidates.size() == 0) {
            return false;
        }

        for (char c: candidates) {
            board[currentX][currentY] = c;
            if (backtrack(board, index + 1)) {
                return true;
            }
            board[currentX][currentY] = '.';
        }

        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
        backtrack(board, 0);
    }
};