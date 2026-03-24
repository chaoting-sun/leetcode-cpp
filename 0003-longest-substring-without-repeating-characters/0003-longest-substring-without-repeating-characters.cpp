class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int s_length = s.size();
        if (s_length == 0) return 0;

        int left = 0;
        unordered_set<char> seen;
        int max_length = 0;

        for (int right = 0; right < s_length; right++) {
            while (seen.count(s[right])) {
                seen.erase(s[left]);
                left++;
            }

            seen.insert(s[right]);
            max_length = max(max_length, right - left + 1);
        }

        return max_length;
    }
};

// trap case: s = aa
// left = 0
// right = 0, seen = { a }, max_length = 1
// right = 1, seen = {}, left = 1, seen = { a }, max_length = 1
// < returns 1

// happy case: s = abc
// trace:
// left = 0
// right = 0
// seen = { a }, max_length = 1
// seen = { a, b }, max_length = 2
// seen = { a, b, c }, max_length = 3
// < returns 3

// base case: s = a
// trace:
// left = 0
// right = 0
// seen = { a }
// max_length = 1
// < returns 1