// Approach: Sliding Window
// Time: O(n)
// Space: O(n)

class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        vector<int> charCount(128);
        int maxLength = 0;
        int start = 0, end = 0;
        int distinctCharacters = 0;
        
        while (end < s.size()) {
            if (charCount[s[end]] == 0) distinctCharacters++;
            charCount[s[end]]++;

            while (distinctCharacters > 2) {
                charCount[s[start]]--;
                if (charCount[s[start]] == 0) {
                    distinctCharacters--;
                }
                start++;
            }

            maxLength = max(maxLength, end - start + 1);
            end++;
        }

        return maxLength;
    }
};