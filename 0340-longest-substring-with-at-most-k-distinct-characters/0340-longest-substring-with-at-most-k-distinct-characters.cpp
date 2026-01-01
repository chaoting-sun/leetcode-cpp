class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        if (k == 0) return 0;
        
        int length = s.size();
        vector<int> freq(128);
        int distinct_char_count = 0;
        int max_length = 0;

        int left = 0, right = 0;
        while (right < length) {
            if (freq[s[right]] == 0) distinct_char_count++;
            freq[s[right]]++;
            while (distinct_char_count > k) {
                freq[s[left]]--;
                if (freq[s[left]] == 0) distinct_char_count--;
                left++;
            }
            max_length = max(max_length, right - left + 1);
            right++;
        }
        return max_length;
    }
};

// trap case:s = 'aa', k = 0 -> returns 0

// happy path: s = 'abaac', k = 2
//              idx 01234
//                  01002
// trace:
// l=0,r=0
// distinct = 1, freq[0] = 1, max length = 1
// l=0,r=1
// distinct = 2, freq[1] = 1, max length = 2
// l=0,r=2
// distinct = 2, freq[0] = 2, max length = 3
// l=0,r=3
// distinct = 2, freq[0] = 3, max length = 4
// l=0,r=4
// distinct = 3, freq[2] = 1
// 3 > 2:
//  freq[0] = 2
//  l=1
// 3 > 2
//  freq[1] = 0, distinct = 2
//  l=2
// max length = 4
// < returns 4

// base case: s = "a", k = 1
// trace:
// l=0,r=0
// distinct_char_count = 1
// freq[0] = 0
// max length = 0-0+1 = 1
// < returns 1

// Submit Error

// TLE: 忘記 right++...
// RE: character 範圍不是小寫而已