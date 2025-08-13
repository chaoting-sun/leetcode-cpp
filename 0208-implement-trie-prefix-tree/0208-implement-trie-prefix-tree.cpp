class Trie {
public:
    Trie* children[26];
    bool is_leaf;

    Trie() {
        for (int i = 0; i < 26; i++) children[i] = nullptr;
        is_leaf = false; 
    }
    
    void insert(string word) {
        Trie* curr = this;

        for (char ch: word) {
            if (!curr->children[ch - 'a']) {
                curr->children[ch - 'a'] = new Trie();
            }
            curr = curr->children[ch - 'a'];
        }
        curr->is_leaf = true;
    }
    
    bool search(string word) {
        Trie* curr = this;
        
        for (char ch: word) {
            if (!curr->children[ch - 'a']) return false;
            curr = curr->children[ch - 'a'];
        }
        return curr->is_leaf;
    }
    
    bool startsWith(string prefix) {
        Trie* curr = this;

        for (char ch: prefix) {
            if (!curr->children[ch - 'a']) return false;
            curr = curr->children[ch - 'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */