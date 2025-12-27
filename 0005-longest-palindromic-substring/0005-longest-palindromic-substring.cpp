class Solution {
public:
    string longestPalindrome(string s) {
        int s_length = s.size();
        if (s_length == 0) return "";
        
        int max_left_idx = 0;
        int max_length = 1;

        // odd
        for (int i = 0; i < s_length; i++) {
            int left = i, right = i;
            while (left > 0 && right < s_length - 1 && s[left - 1] == s[right + 1]) {
                left--;
                right++;    
            }
            if (right - left + 1 > max_length) {
                max_length = right - left + 1;
                max_left_idx = left;
            }
        }
        // even
        for (int i = 1; i < s_length; i++) {
            if (s[i - 1] != s[i]) continue;

            int left = i - 1, right = i;
            while (left > 0 && right < s_length - 1 && s[left - 1] == s[right + 1]) {
                left--;
                right++;
            }
            if (right - left + 1 > max_length) {
                max_length = right - left + 1;
                max_left_idx = left;
            }
        }
        return s.substr(max_left_idx, max_length);
    }
};
