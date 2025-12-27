class Solution {
public:
    int countSubstrings(string s) {
        int s_length = s.size();
        if (s_length == 0) return 0;

        int substring_count = 0;

        auto expand = [&](int left, int right) {
            while (left >= 0 && right < s_length && s[left] == s[right]) {
                substring_count++;
                left--;
                right++;
            }
        };

        for (int i = 0; i < s_length; i++) {
            expand(i, i);
        }
        for (int i = 1; i < s_length; i++) {
            expand(i - 1, i);
        }
        return substring_count;
    }
};