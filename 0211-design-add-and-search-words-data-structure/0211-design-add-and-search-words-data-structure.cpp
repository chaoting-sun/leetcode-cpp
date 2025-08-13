// addWord
// Time: O(L). L is the length of word. at each step, we either examine or create a node in the trie
// Space: O(L). In worst case, we create L nodes in the trie

// Time: O(L*26^m). in worst case, in every level <= L, all characters (26) exists and so do the
// characters in the next level. Also, suppose that there are m ".", each expand 26 possibilities,
// so there are 26^m paths. each path has length L, so the time is L*26^m.
// Space:
// - 1st Version: O(L). there will be L recursive stacks where L is the word length
// - 2nd Version: if there is no ".", then O(1); if there are m ".", then O(m) as there will be recursive stacks

class CharNode {
public:
    unordered_map<char, CharNode*> children;
    bool is_word;

    CharNode() {
        is_word = false;
    }
};

class WordDictionary {
public:
    CharNode* root;

    WordDictionary() {
        root = new CharNode();
    }
    
    void addWord(string word) {
        CharNode* curr = root;

        for (char ch: word) {
            if (!curr->children.count(ch)) {
                curr->children[ch] = new CharNode();
            }
            curr = curr->children[ch];
        }
        curr->is_word = true;
    }
    
    bool search(string word) {
        return searchInNode(word, 0, root);
    }

    // Version 1

    // bool searchInNode(string &word, int idx, CharNode* root) {
    //     if (idx >= word.size()) return root->is_word;

    //     if (word[idx] == '.') {
    //         for (auto node: root->children) {
    //             if (searchInNode(word, idx + 1, node.second)) {
    //                 return true;
    //             }
    //         }
    //     } else {
    //         if (root->children.count(word[idx]) && searchInNode(word, idx + 1, root->children[word[idx]])) {
    //             return true;
    //         }
    //     }
    //     return false;
    // }

    // Version 2

    bool searchInNode(string &word, int start_idx, CharNode* node) {
        for (int i = start_idx; i < word.size(); i++) {
            char ch = word[i];

            if (node->children.count(ch)) {
                node = node->children[ch];
            } else {
                if (ch == '.') {
                    for (auto child: node->children) {
                        if (searchInNode(word, i + 1, child.second)) {
                            return true;
                        }
                    }
                }
                return false;
            }
        }

        return node->is_word;
    }
};


/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */