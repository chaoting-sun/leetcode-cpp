class Solution {
public:
    // Approach: backtracking
    // This is a classic "generate all valid partitions" problem -> backtracking
    // explore the string left to right. at each start index, I try every possible end index;
    // if s[start..i] is a palindrome, we choose it, recurse from i+1, and then un-choose (pop)
    // when we reach the end, I've built one valid partition and addit to the 
    
    // Time: O(n * 2^n)
    // - the number of substrings: in worst case all characters are the same, such as aa..aa. for
    // a string aa..aa with length n, there are n - 1 gaps that we can choose to cut off. so
    // there are 2^(n-1) combinations. so there are O(2^n) substring
    // - the execution time: it takes O(n) to generate each substring
    
    // Space: O(n)
    // The max. depth of the recursive call stack will be O(n)

    // vector<vector<string>> ans;

    // bool isPalindrome(string &s, int start, int end) {
    //     while (start < end) {
    //         if (s[start] != s[end]) return false;
    //         start++;
    //         end--;
    //     }
    //     return true;
    // }

    // void searchPalindrome(string &s, int start, vector<string> substrings) {
    //     if (start == s.size()) {
    //         ans.push_back(substrings);
    //         return;
    //     }

    //     for (int i = start; i < s.size(); i++) {
    //         if (isPalindrome(s, start, i)) {
    //             substrings.push_back(s.substr(start, i - start + 1));
    //             searchPalindrome(s, i + 1, substrings);
    //             substrings.pop_back();
    //         }
    //     }
    // }

    // vector<vector<string>> partition(string s) {
    //     searchPalindrome(s, 0, vector<string>());
    //     return ans;
    // }

    // Intuition: to check if a substring [start...end] is a palindrome, we can check:
    // if start == end: is palindrome
    // elif start + 1 == end & s[start + 1] == s[end]: is a palindrome
    // elif start + 1 < end & s[start+1..end-1] is a palindrom: is a palindrome
    // so there are overlapping subproblems    

    // Approach: Backtracking + dp[][]

    vector<vector<string>> ans;
    vector<vector<bool>> dp;

    void searchPalindrome(string &s, int start, vector<string> substrings) {
        if (start == s.size()) {
            ans.push_back(substrings);
            return;
        }

        for (int end = start; end < s.size(); end++) {
            if (start == end || s[start] == s[end] && (start + 1 == end || dp[start + 1][end - 1])) {
                dp[start][end] = true;
                substrings.push_back(s.substr(start, end - start + 1));
                searchPalindrome(s, end + 1, substrings);
                substrings.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        int n = s.size();
        dp.resize(n, vector<bool>(n, false));

        searchPalindrome(s, 0, vector<string>());
        return ans;
    }
};