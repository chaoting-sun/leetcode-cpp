class Solution {
public:
    // Approach1: check the rows, cols, and cells separately in order
    // and track occurence by set.
    // Time: O(n**2), where n is the board length (it is 9). For each
    // check, there are at worst n**2 "find" and "insert".
    // Space: O(n_cell**2), where n is the cell size (it is 3)

    // bool isValidSudoku(vector<vector<char>>& board) {
    //     int n = 9;
    //     int n_cell = 3;
    //     int n_block = n / n_cell;

    //     for (int row = 0; row < n; row++) {
    //         unordered_set<char> s;
    //         for (int col = 0; col < n; col++) {
    //             char c = board[row][col];
    //             if (c == '.') continue;
    //             if (s.find(c) != s.end()) {
    //                 return false;
    //             }
    //             s.insert(c);
    //         }
    //     }

    //     for (int col = 0; col < n; col++) {
    //         unordered_set<char> s;
    //         for (int row = 0; row < n; row++) {
    //             char c = board[row][col];
    //             if (c == '.') continue;
    //             if (s.find(c) != s.end()) {
    //                 return false;
    //             }
    //             s.insert(c);
    //         }
    //     }

    //     for (int brow = 0; brow < n; brow += n_cell) { // block row
    //         for (int bcol = 0; bcol < n; bcol += n_cell) { // block column
    //             unordered_set<char> s;
    //             for (int row = brow; row < brow + n_cell; row++) {
    //                 for (int col = bcol; col < bcol + n_cell; col++) {
    //                     char c = board[row][col];
    //                     if (c == '.') continue;
    //                     if (s.find(c) != s.end()) {
    //                         return false;
    //                     }
    //                     s.insert(c);
    //                 }
    //             }
    //         }
    //     }

    //     return true;
    // }

    // Approach2: track occurence by three sets: for rows, cols, and blocks
    // Time: O(n**2), where n is the board length
    // Space: O(n**2). rows, cols, blocks contains 3 * n**2 elements

    bool isValidSudoku(vector<vector<char>>& board) {
        int n = 9;
        int n_cell = 3;
        int n_block = n / n_cell;

        vector<unordered_set<char>> rows(n);
        vector<unordered_set<char>> cols(n);
        vector<unordered_set<char>> blocks(n);

        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                int c = board[row][col];
                if (c == '.') continue;

                if (rows[row].find(c) != rows[row].end()) return false;
                rows[row].insert(c);

                if (cols[col].find(c) != cols[col].end()) return false;
                cols[col].insert(c);

                int block_row = row / n_cell;
                int block_col = col / n_cell;
                int bid = block_row * n_cell + block_col;
                if (blocks[bid].find(c) != blocks[bid].end()) return false;
                blocks[bid].insert(c);
            }
        }

        return true;
    }
};