class Solution {
private:
    int m;
    int n;

public:
    bool backtrack(vector<vector<char>>& board, string& word, int i, int x, int y) {
        if (x < 0 || x >= m || y < 0 || y >= n || board[x][y] != word[i]) return false;

        if (i == word.size() - 1) return true;
        
        char tmp = board[x][y];
        board[x][y] = '#';

        if (backtrack(board, word, i + 1, x + 1, y) ||
            backtrack(board, word, i + 1, x - 1, y) ||
            backtrack(board, word, i + 1, x, y + 1) ||
            backtrack(board, word, i + 1, x, y - 1) 
        ) {
            return true;
        }
        
        board[x][y] = tmp;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();

        for (int x = 0; x < m; x++) {
            for (int y = 0; y < n; y++) {
                if (board[x][y] == word[0] && backtrack(board, word, 0, x, y)) {
                    return true;
                }
            }
        }
        return false;
    }
};