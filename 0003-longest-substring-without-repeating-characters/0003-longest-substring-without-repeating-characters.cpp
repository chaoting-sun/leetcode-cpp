class Solution {
public:
    // Approach1: Sliding Window (Two Pointers + Set)
    // Time: O(2n) = O(n), where n is the string length
    // Space: O(min(n, m)), where n is the string length and m is the size of alphabet.

    // int lengthOfLongestSubstring(string s) {
    //     int n = s.size();
    //     if (n == 0) return 0;

    //     int left = 0, right = 0;
    //     int max_len = 1;
    //     unordered_set<char> ch{ s[0] };

    //     while (right < n - 1) {
    //         // add the next character if it is not in the character set (ch)
    //         if (ch.find(s[right + 1]) == ch.end()) {
    //             ch.insert(s[right + 1]);
    //             right++;
    //             max_len = max(max_len, right - left + 1);
    //             continue;
    //         }

    //         // if the next has been in the set, then:
    //         // if there are only one character, then move left and right by one step (ex: s = bb, left = right = 0)
    //         if (left == right) {
    //             left++;
    //             right++;
    //         } else if (left < right) {
    //             ch.erase(s[left]);
    //             left++;
    //         }
    //     }

    //     return max_len;
    // }

    // Approach2: Sliding Window (Two Pointers + Map (count the characters))
    // Time: O(n)
    // Space: O(min(n, m)), where n is the string length and m is the size of alphabet.

    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if (n == 0) return 0;

        vector<int> charCount(128, 0);
        int start = 0, end = 0;
        int maxLen = 1;

        while (end < n) {
            char ch = s[end];
            charCount[ch]++;

            while (charCount[ch] > 1) {
                charCount[s[start]]--;
                start++;
            }

            maxLen = max(maxLen, end - start + 1);
            end++;
        }

        return maxLen;
    }

    // Approach3: Optimized Sliding Window.
    // Record the character position ch2index such that once s[right] has been in the map, left can jump to the position ch2index[s[right]] + 1
    
    // int lengthOfLongestSubstring(string s) {
    //     int n = s.size();
    //     int left = 0, right = 0;
    //     int max_len = 0;
    //     unordered_map<char, int> ch2index;

    //     while (right < n) {
    //         if (ch2index.find(s[right]) != ch2index.end() && ch2index[s[right]] >= left) {
    //             left = ch2index[s[right]] + 1;
    //         }
    //         ch2index[s[right]] = right;
    //         max_len = max(max_len, right - left + 1);
    //         right++;
    //     }

    //     return max_len;
    // }
};

