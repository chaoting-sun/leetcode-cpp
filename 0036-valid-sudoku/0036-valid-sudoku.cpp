class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = 9;
        int n_cell = 3;
        int n_block = n / n_cell;

        for (int row = 0; row < n; row++) {
            set<char> s;
            for (int col = 0; col < n; col++) {
                char c = board[row][col];
                if (c == '.') continue;
                if (s.find(c) != s.end()) {
                    return false;
                }
                s.insert(c);
            }
        }

        for (int col = 0; col < n; col++) {
            set<char> s;
            for (int row = 0; row < n; row++) {
                char c = board[row][col];
                if (c == '.') continue;
                if (s.find(c) != s.end()) {
                    return false;
                }
                s.insert(c);
            }
        }

        for (int brow = 0; brow < n; brow += n_cell) { // block row
            for (int bcol = 0; bcol < n; bcol += n_cell) { // block column
                set<char> s;
                for (int row = brow; row < brow + n_cell; row++) {
                    for (int col = bcol; col < bcol + n_cell; col++) {
                        char c = board[row][col];
                        if (c == '.') continue;
                        if (s.find(c) != s.end()) {
                            return false;
                        }
                        s.insert(c);
                    }
                }
            }
        }

        return true;
    }
};