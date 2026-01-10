class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<bool> seen(128);
        int left = 0;
        int max_len = 0;

        for (int right = 0; right < s.size(); right++) {
            while (seen[s[right]]) {
                seen[s[left]] = false;
                left++;
            }
            seen[s[right]] = true;
            max_len = max(max_len, right - left + 1);
        }
        return max_len;
    }
};