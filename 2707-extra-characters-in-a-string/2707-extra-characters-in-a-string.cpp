// ## Understand

// what is the length of s?
// - 1 <= s.length <= 50

// what is the size of dictionary?
// - 1 <= dictionary.length <= 50

// are all the characters lower English letters?
// - yes.


// ## Match

// One way is to try all combinations from the dictionary, but the time complexity is very high.
// Another method is DP. The observation is that the answer of a prefix of s can be constructed
// by the answer of it's prefix. For example, for s = "leetcode" and dictionary = ["leet", "code"],
// s[7] can be the suffix of "code", so the answer of s[0..7] can be constructed by that of s[0..3].
// So, it is possible that it can be solved by DP.
// suppose that dp[i] is the minimum number of extra characters from s[0..i], then
// if s[i] is an extra character, then dp[i] = min(dp[i], dp[i - 1] + 1)
// if s[i] can be the last character of the words in dictionary, then dp[i] = min(dp[i], dp[i-k1], dp[i-k2], ...),
// where the k1 and k2 are the length of the words that match
// When searching for the words that match, it takes the size of dictionary to search. I will
// build a vector of strings with entry the suffix character and values the words given the suffix character.


// ## Plan

// My plan is create a dp array with length n + 1. dp[i + 1] is the minimum number of extra characters
// in s[0..i]. dp[0] represents the empty string.
// I iterate s, for each i, I have two choices to update:
// - s[i] is an extra character: dp[i + 1] = min(dp[i + 1], dp[i] + 1)
// - s[i] is the last character of the words in dictionary: dp[i + 1] = min(dp[i + 1], dp[i + 1 - k1], ...)
// I use the vector of strings to efficiently search words given the suffix s[i]


// ## Implementation

// class Solution {
// public:
//     int minExtraChar(string s, vector<string>& dictionary) {
//         int s_length = s.size();
//         if (s_length == 0) return 0;
        
//         vector<vector<string>> suffix_lookup(26);
//         for (const string& word: dictionary) {
//             char last_char = word.back();
//             suffix_lookup[last_char - 'a'].push_back(word);
//         }

//         vector<int> dp(s_length + 1, s_length);
//         dp[0] = 0;
//         // string_view s_view(s);

//         for (int i = 0; i < s_length; i++) {
//             // s[i] is an extra character
//             dp[i + 1] = min(dp[i + 1], dp[i] + 1);
//             for (const string& word: suffix_lookup[s[i] - 'a']) {
//                 int word_length = word.size();
//                 if (word_length > i + 1) continue;
                
//                 // if (word == s_view.substr(i - word_length + 1, word_length)) {
//                 if (s.compare(i - word_length + 1, word_length, word) == 0) {
//                     dp[i + 1] = min(dp[i + 1], dp[i + 1 - word_length]);
//                 }
//             }
//         }

//         return dp[s_length];
//     }
// };


// ## Review

// test case: s = "a", dictionary = ["a"]
// trace:
// s_length = 1
// suffix_lookup[0] = ['a']
// dp = [1,1]
// dp = [0,1]
// i=0
//  dp[1] = min(dp[1],dp[0]+1) = 1
//  suffix_lookup[0] = ['a']
//      word_length = 1
//      cond: 1 > 1. no
//      cond: 'a' = s[0,1] = 'a'. yes
//          dp[1] = min(dp[1], dp[0]) = min(1, 0) = 0
// returns dp[1] = 0

// test case: s = 'abcab', dictionary = ['ab']
// trace:
// s_length = 5
// suffix_lookup[1] = ['ab']
// dp = [0,5,5,5,5,5]
// i=0
//  dp[1] = min(dp[1], dp[0]+1) = 1
// i=1
//  dp[2] = min(dp[2], dp[1]+1) = 2
//  word = 'ab'
//  cond: 'ab' = s[0..1]. yes
//  dp[2] = min(2, 0) = 0
// i=2
//  dp[3] = min(dp[3], 0+1) = 1
// i=3
//  dp[4] = min(5,1+1) = 2
// i=4
//  dp[5] = min(5, 2+1) = 3
//  word = 'ab'
//  cond: 'ab' = s[4..5]. yes
//  dp[5] = min(5, dp[4+1-2]) = 1
// returns 1


// ## Evaluation
// n = length of s
// ld = length of dictionary; l = word length; lw = length of suffix_lookup[i]
// Time: O(ld*l+n*lw*l) = O((ld+n*lw)*l)
// The time complexity are contributed by building the suffix_lookup and the dp iteration
// - suffix_lookup: O(ld*l)
// - dp iteration: O(n*lw*l)
// Space: O(C + n), where C is the total number of characters.


// Submit Error

class Solution {
private:
    struct Trie {
        vector<Trie*> children[26];
        bool is_word = false;
        Trie() {}
    };

    Trie* buildTrie(const vector<string>& dictionary) {
        Trie* root = new Trie();
        for (const string& word: dictionary) {
            Trie* curr = root;
            for (char ch: word) {
                if (!curr->children[ch - 'a']) {
                    curr->children[ch - 'a'] = new Trie();
                }
                curr = curr->child[ch - 'a'];
            }
            curr->is_word = true;
        }
        return root;
    }

public:
    int minExtraChar(string s, vector<string>& dictionary) {
        int s_length = s.size();
        if (s_length == 0) return 0;
        
        Trie* trie = buildTrie(dictionary);

        vector<int> dp(s_length + 1, s_length);
        dp[0] = 0;

        for (int i = 0; i < s_length; i++) {
            // not choose s[i]
            dp[i + 1] = min(dp[i + 1], dp[i] + 1);
            // choose s[i]
            Trie* curr = trie;
            for (int j = i; j < s_length; j++) {
                if (!curr->children[s[j]]) break;
                curr = curr->children[s[j]];
                if (curr->is_word) {
                    dp[j + 1] = min(dp[j + 1], dp[i]);
                }
            }
        }

        return dp[s_length];
    }
};