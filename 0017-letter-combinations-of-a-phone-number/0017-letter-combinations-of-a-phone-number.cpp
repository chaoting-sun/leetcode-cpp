class Solution {
public:
    // Approach: backtracking

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