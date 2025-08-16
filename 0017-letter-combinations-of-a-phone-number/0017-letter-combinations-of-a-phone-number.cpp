class Solution {
public:
    // Approach: backtracking
    // Time: O(4^n * n). 4 is maximum number of additional paths for every digits (for 7 or 9).
    // if there are n digits, there are at most 4^n possible solutions. to build a subtring we
    // need O(n) time
    // Space: O(n). we recursively explore n digits so there are n recursive stacks.

    vector<string> ans;

    void backtrack(unordered_map<char, vector<char>>& digit2chars, string& digits, int i, string substring) {
        if (i == digits.size()) {
            ans.push_back(substring);
            return;
        }

        vector<char> characters = digit2chars[digits[i]];

        for (char ch: characters) {
            substring += ch;
            backtrack(digit2chars, digits, i + 1, substring);
            substring.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return ans;

        unordered_map<char, vector<char>> digit2chars {
            {'2', { 'a', 'b', 'c' }},
            {'3', { 'd', 'e', 'f' }},
            {'4', { 'g', 'h', 'i' }},
            {'5', { 'j', 'k', 'l' }},
            {'6', { 'm', 'n', 'o' }},
            {'7', { 'p', 'q', 'r', 's'}},
            {'8', { 't', 'u', 'v' }},
            {'9', { 'w', 'x', 'y', 'z' }},
        };
        
        string substring = ""; 
        backtrack(digit2chars, digits, 0, substring);
        return ans;
    }
};