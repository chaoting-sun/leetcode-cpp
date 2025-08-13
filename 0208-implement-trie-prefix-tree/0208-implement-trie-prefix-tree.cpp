class TrieNode {
public:
    TrieNode* children[26];
    bool is_leaf; // as the last character of a word

    TrieNode() {
        for (int i = 0; i < 26; i++) children[i] = nullptr;
        is_leaf = false;
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* curr = root;

        for (char ch: word) {
            if (!curr->children[ch - 'a']) {
                curr->children[ch - 'a'] = new TrieNode();
            }
            curr = curr->children[ch - 'a'];
        }
        curr->is_leaf = true;
    }
    
    bool search(string word) {
        TrieNode* curr = root;
        
        for (char ch: word) {
            if (!curr->children[ch - 'a']) return false;
            curr = curr->children[ch - 'a'];
        }
        return curr->is_leaf;
    }
    
    bool startsWith(string prefix) {
        TrieNode* curr = root;

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