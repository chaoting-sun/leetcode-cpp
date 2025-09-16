class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int n = s.size();
        if (n == 0 || k == 0) return 0;
        
        vector<int> charCount(128, 0);
        int maxLength = 1;
        int start = 0, end = 0;
        int distinctCharacters = 0;
        
        while (end < n) {
            if (charCount[s[end]] == 0) distinctCharacters++;
            charCount[s[end]]++;

            while (distinctCharacters > k) {
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