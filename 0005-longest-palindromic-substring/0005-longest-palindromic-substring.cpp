class Solution {
public:
    string longestPalindrome(string s) {
        int s_length = s.size();
        if (s_length == 0) return "";
        
        int max_left_idx = 0;
        int max_length = 1;

        auto expand = [&](int left, int right) {
            while (left >= 0 && right < s_length && s[left] == s[right]) {
                left--;
                right++;    
            }
            int current_length = right - left - 1;
            if (current_length > max_length) {
                max_length = current_length;
                max_left_idx = left + 1;
            }
        };

        // odd and even
        for (int i = 0; i < s_length; i++) expand(i, i);
        for (int i = 1; i < s_length; i++) expand(i - 1, i);
        
        return s.substr(max_left_idx, max_length);
    }
};
