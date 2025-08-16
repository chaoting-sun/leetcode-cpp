class Solution {
private:
    int m;
    int n;

public:
    // Approach: backtracking
    // Treat the board as a grid graph. from every cell that matches the first character, start a DFS
    // Then at each step i, temporarily mark the cell as visited so we don't reuse it in the current path

    // Time: O(m*n*3^L)
    // there are m*n grids so we'll try m*n cell as a start. from a start the branching factor
    // is at most 4 on the first move, but then <=3 thereafter (you cannot go back to the visited cell)
    // Space: O(L)
    // O(L) recursion stack depth

    bool backtrack(vector<vector<char>>& board, string& word, int i, int x, int y) {
        if (x < 0 || x >= m || y < 0 || y >= n || board[x][y] != word[i]) return false;

        if (i == word.size() - 1) return true;
        
        char tmp = board[x][y];

        // mark as visited
        board[x][y] = '#';

        // search in the selection list
        if (backtrack(board, word, i + 1, x + 1, y) ||
            backtrack(board, word, i + 1, x - 1, y) ||
            backtrack(board, word, i + 1, x, y + 1) ||
            backtrack(board, word, i + 1, x, y - 1) 
        ) {
            return true;
        }
        
        // mark as unvisited to not affect the other backtracking path
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