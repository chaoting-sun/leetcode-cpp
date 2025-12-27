class Solution {
private:
    int max_left_idx = 0;
    int max_length = 1;

    void expand(string& s, int& left, int& right) {
        int s_length = s.size();
        while (left > 0 && right < s_length - 1 && s[left - 1] == s[right + 1]) {
            left--;
            right++;    
        }
    }

    void updateMax(int left, int right) {
        if (right - left + 1 > max_length) {
            max_length = right - left + 1;
            max_left_idx = left;
        }   
    }

public:
    string longestPalindrome(string s) {
        int s_length = s.size();
        if (s_length == 0) return "";
        

        // odd
        for (int i = 0; i < s_length; i++) {
            int left = i, right = i;
            expand(s, left, right);
            updateMax(left, right);
        }
        // even
        for (int i = 1; i < s_length; i++) {
            if (s[i - 1] != s[i]) continue;
            int left = i - 1, right = i;
            expand(s, left, right);
            updateMax(left, right);
        }
        return s.substr(max_left_idx, max_length);
    }
};
