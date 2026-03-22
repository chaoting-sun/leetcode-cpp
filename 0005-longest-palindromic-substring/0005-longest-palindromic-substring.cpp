class Solution {
private:
    string getPalindrome(string& s, int left, int right) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            left--;
            right++;
        }
        return s.substr(left + 1, right - left - 1);
    }

public:
    string longestPalindrome(string s) {
        int s_length = s.size();
        
        int max_length = 0;
        string max_palindrome = "";

        for (int i = 0; i < s_length; i++) {
            string curr = getPalindrome(s, i, i);
            if (curr.size() > max_length) {
                max_length = curr.size();
                max_palindrome = move(curr);
            }
        }
        
        for (int i = 0; i < s_length - 1; i++) {
            string curr = getPalindrome(s, i, i + 1);
            if (curr.size() > max_length) {
                max_length = curr.size();
                max_palindrome = move(curr);
            }
        }

        return max_palindrome;
    }
};

// babad
// i = 1
// getPalindrome(1, 1)
//  left = 1, right = 1
//  left = 0, right = 2
//  left = -1, right = 3
//  start at 0; length = 3