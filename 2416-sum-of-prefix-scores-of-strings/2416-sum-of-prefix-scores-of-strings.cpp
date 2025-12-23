// Understand

// Can the word be repetitive?
// It can be.

// Can any word be empty string?
// No. 1 <= words[i].length <= 1000

// What is the size range of words. Can it be empty?
// No. 1 <= words.length <= 1000


// Match & Plan

// It is a trie problem, as we need to record the score of all prefix of word[i], and
// the words may share common prefix.
// The steps will be divided into two parts:
// 1. build a trie using the words. for each trie node, we initialize the count by 0
// and add it by 1 when passing through it.
// 2. iterate the words, traversing the trie and summing up the total score.


// Implement

class Solution {
private:
    struct TrieNode {
        TrieNode* children[26];
        int count = 0;
        TrieNode() {
            for (int i = 0; i < 26; i++) {
                children[i] = nullptr;
            }
        }
    };

    TrieNode* buildTrie(const vector<string>& words) {
        TrieNode* root = new TrieNode();

        for (const string& word: words) {
            TrieNode* curr = root;
            for (char w: word) {
                if (!curr->children[w - 'a']) {
                    curr->children[w - 'a'] = new TrieNode();
                }
                curr = curr->children[w - 'a'];
                curr->count++;
            }
        }
        return root;
    }

public:
    vector<int> sumPrefixScores(vector<string>& words) {
        int words_length = words.size();
        if (words_length == 0) return {};

        TrieNode* root = buildTrie(words);
        vector<int> answer(words_length);
        for (int i = 0; i < words_length; i++) {
            int total_count = 0;
            TrieNode* curr = root;
            for (char w: words[i]) {
                curr = curr->children[w - 'a'];
                total_count += curr->count;
            }
            answer[i] = total_count;
        }

        return answer;
    }
};


// Review

// test case: words = ['a']
// trace:
// words_length = 1
// > buildTrie
//  create root
//  root->children[0]
// > answer(1)
// > for loop
//  i = 0
//  total_count = 0
//  curr = root
//  total_count = 1


// Evaluation

// Time complexity: O(C), where C is the number of characters in words
// for building a trie or finding the score, we need to process all characters
// Space complexity: O(C). The number of created trie nodes is less than the number of characters in words


// Submit Error

// for (char w: words)
// to
// for (char w: word)

// Memory Limit Exceeded
// original: created vector<TreeNode*> children with children.assign(26, nullptr)
// to
// now: unordered_map<char, TreeNode*>
