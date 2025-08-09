class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if (n == 0) return 0;

        int left = 0, right = 0;
        int max_len = 1;
        unordered_set<char> ch{ s[0] };

        while (right < n - 1) {
            if (ch.find(s[right + 1]) == ch.end()) {
                ch.insert(s[right + 1]);
                right++;
                max_len = max(max_len, right - left + 1);
                continue;
            }

            if (left == right) {
                left++;
                right++;
            } else if (left < right) {
                ch.erase(s[left]);
                left++;
            }
        }

        return max_len;
    }
};
