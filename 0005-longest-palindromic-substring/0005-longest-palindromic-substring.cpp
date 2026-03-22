class Solution {
public:
    string longestPalindrome(string s) {
        int s_length = s.size();
        
        int max_length = 0;
        int max_length_idx = -1;

        auto expand = [&](int left, int right) {
            while (left >= 0 && right < s.size() && s[left] == s[right]) {
                left--;
                right++;
            }
            int curr_length = right - left - 1;
            if (curr_length > max_length) {
                max_length = curr_length;
                max_length_idx = left + 1;
            }
        };

        for (int i = 0; i < s_length; i++) {
            expand(i, i);
        }
        
        for (int i = 0; i < s_length - 1; i++) {
            expand(i, i + 1);
        }

        return s.substr(max_length_idx, max_length);
    }
};

// babad
// i = 1
// getPalindrome(1, 1)
//  left = 1, right = 1
//  left = 0, right = 2
//  left = -1, right = 3
//  start at 0; length = 3