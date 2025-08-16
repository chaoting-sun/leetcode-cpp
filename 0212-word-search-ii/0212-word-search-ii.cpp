// Approach: Trie + backtracking

class TrieNode {
public:
    string word;
    TrieNode* children[26];
    TrieNode(): word("") {
        for (int i = 0; i < 26; i++) children[i] = nullptr;
    }
};

class Solution {
public:
    vector<string> ans;
    TrieNode* trie_head;
    int m;
    int n;

    void buildTrie(string word, int i, TrieNode* prev) {
        // termination
        if (i == word.size()) {
            prev->word = word;
            return;
        }

        if (!prev->children[word[i] - 'a']) {
            prev->children[word[i] - 'a'] = new TrieNode();
        }
        TrieNode* curr = prev->children[word[i] - 'a'];

        buildTrie(word, i + 1, curr);
    }

    void findWord(vector<vector<char>>& board, int i, int j, TrieNode* curr, vector<vector<bool>>& visited) {
        // handle edge case
        if (i < 0 || i >= m || j < 0 || j >= n) return;
        if (!curr->children[board[i][j] - 'a']) return;
        if (visited[i][j]) return;

        // enter the cell
        visited[i][j] = true;
        curr = curr->children[board[i][j] - 'a'];
        if (!curr->word.empty()) {
            ans.push_back(curr->word);
            curr->word.clear();
        }

        // enter the adjacent cells
        findWord(board, i + 1, j, curr, visited);
        findWord(board, i - 1, j, curr, visited);
        findWord(board, i, j + 1, curr, visited);
        findWord(board, i, j - 1, curr, visited);

        // unvisit
        visited[i][j] = false;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        // build trie from words
        trie_head = new TrieNode();
        for (string word: words) {
            buildTrie(word, 0, trie_head);
        }        
        
        // backtrack from every cell
        m = board.size();
        n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (trie_head->children[board[i][j] - 'a']) {
                    findWord(board, i, j, trie_head, visited);
                }
            }
        }
        return ans;
    }
};