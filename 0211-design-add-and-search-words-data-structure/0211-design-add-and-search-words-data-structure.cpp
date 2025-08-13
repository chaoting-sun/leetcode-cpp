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

    bool searchInNode(string &word, int idx, CharNode* root) {
        if (idx >= word.size()) return root->is_word;

        if (word[idx] == '.') {
            for (auto node: root->children) {
                if (searchInNode(word, idx + 1, node.second)) {
                    return true;
                }
            }
        } else {
            if (root->children.count(word[idx]) && searchInNode(word, idx + 1, root->children[word[idx]])) {
                return true;
            }
        }
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */