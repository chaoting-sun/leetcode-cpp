class Character {
public:
    Character* children[26];
    bool is_word;

    Character() {
        for (int i = 0; i < 26; i++) children[i] = nullptr;
        is_word = false;
    }
};

class WordDictionary {
public:
    Character* root;

    WordDictionary() {
        root = new Character();
    }
    
    void addWord(string word) {
        Character* curr = root;

        for (char ch: word) {
            if (!curr->children[ch - 'a']) {
                curr->children[ch - 'a'] = new Character();
            }
            curr = curr->children[ch - 'a'];
        }
        curr->is_word = true;
    }
    
    bool search(string word) {
        return searchInNode(word, 0, root);
    }

    bool searchInNode(string &word, int idx, Character* root) {
        if (idx >= word.size()) return root->is_word;

        char ch = word[idx];
        if (ch == '.') {
            for (int i = 0; i < 26; i++) {
                if (root->children[i] && searchInNode(word, idx + 1, root->children[i])) {
                    return true;
                }
            }
        } else {
            if (root->children[ch - 'a'] && searchInNode(word, idx + 1, root->children[ch - 'a'])) {
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