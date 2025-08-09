class Solution {
public:
    // Approach: Sliding Window
    // Time: O(n)
    // Space: O(#charset)

    int characterReplacement(string s, int k) {
        int left = 0, right = 0;
        int n = s.size();
        int max_len = 0;
        vector<int> char_cnt(26, 0);

        while (right < n) {
            // right: add new character
            char_cnt[s[right] - 'A']++;

            // left: move to where [left, right] meets the constraint
            while ((right - left + 1) - *max_element(char_cnt.begin(), char_cnt.end()) > k) {
                char_cnt[s[left] - 'A']--;
                left++;
            }

            // update the max. length
            max_len = max(max_len, right - left + 1);

            // move to the next
            right++;
        }

        return max_len;
    }
};