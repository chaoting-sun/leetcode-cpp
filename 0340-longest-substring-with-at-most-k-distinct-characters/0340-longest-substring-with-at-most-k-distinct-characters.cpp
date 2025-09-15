class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int n = s.size();
        if (n == 0 || k == 0) return 0;
        
        unordered_map<char, int> charCount;
        int maxLength = 1;
        int start = 0, end = 0;
        
        while (end < n) {
            charCount[s[end]]++;
            if (charCount.size() > k) {
                maxLength = max(maxLength, end - start);
                while (charCount.size() > k) {
                    charCount[s[start]]--;
                    if (charCount[s[start]] == 0) {
                        charCount.erase(s[start]);
                    }
                    start++;
                }
            }
            end++;
        }
    
        return max(maxLength, end - start);
    }
};