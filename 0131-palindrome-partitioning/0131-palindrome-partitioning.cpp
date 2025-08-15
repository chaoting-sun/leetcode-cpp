class Solution {
public:
    vector<vector<string>> ans;

    bool isPalindrome(string &s, int start, int end) {
        while (start < end) {
            if (s[start] != s[end]) return false;
            start++;
            end--;
        }
        return true;
    }

    void searchPalindrome(string &s, int start, vector<string> substrings) {
        if (start == s.size()) {
            ans.push_back(substrings);
            return;
        }

        for (int i = start; i < s.size(); i++) {
            if (isPalindrome(s, start, i)) {
                substrings.push_back(s.substr(start, i - start + 1));
                searchPalindrome(s, i + 1, substrings);
                substrings.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        searchPalindrome(s, 0, vector<string>());
        return ans;
    }
};