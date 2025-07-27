class Solution {
public:
    // Approach 1: Sort both strings and compare
    // Time: O(n log n + m log m), where n = len(s), m = len(t)
    // Space: O(1) extra (sorting is in-place; ignores input copies)

    // bool isAnagram(string s, string t) {
    //     if (s.size() != t.size()) return false;
    //     sort(s.begin(), s.end());
    //     sort(t.begin(), t.end());

    //     for (int i = 0; i < s.size(); i++) {
    //         if (s[i] != t[i]) {
    //             return false;
    //         }
    //     }

    //     return true;
    // }

    // Approach 2: Counter with unordered_map + distinct count
    // Count characters in s, track number of distinct characters,
    // decrement counts with t and verify all reach zero.
    // Time: O(n + m)
    // Space: O(k), where k = number of distinct characters (O(1) if limited to lowercase letters)

    // bool isAnagram(string s, string t) {
    //     if (s.size() != t.size()) return false;

    //     unordered_map<char, int> counts;
    //     int n_distincts = 0;
    //     int length = s.size();

    //     for (int i = 0; i < length; i++) {
    //         if (counts.find(s[i]) == counts.end()) {
    //             counts.insert({ s[i], 1 });
    //             n_distincts++;
    //         } else {
    //             counts[s[i]]++;
    //         }
    //     }

    //     for (int i = 0; i < length; i++) {
    //         // the element in t does not exist in s
    //         if (counts.find(t[i]) == counts.end()) {
    //             return false;
    //         }

    //         counts[t[i]]--;
            
    //         // t has more t[i] than s
    //         if (counts[t[i]] < 0) {
    //             return false;
    //         }
    //         // has found the same number of t[i] in s
    //         if (counts[t[i]] == 0) {
    //             n_distincts--;
    //         }
    //     }

    //     return n_distincts == 0;
    // }

    // Approach 3: Simplified counter (no distinct tracking)
    // Note that we do not have to check if s contains extra
    // characters not in "t" because an extra character in t
    // comes at the expense of an extra character in s.
    // Time: O(n + m)
    // Space: O(k), where k = number of distinct characters (O(1) if limited to lowercase letters)

    // bool isAnagram(string s, string t) {
    //     if (s.size() != t.size()) return false;
    //     unordered_map<char, int> counts;
    //     int length = s.size();
    //     for (int i = 0; i < length; i++) {
    //         counts[s[i]]++;
    //     }
    //     for (int i = 0; i < length; i++) {
    //         counts[t[i]]--;
    //         if (counts[t[i]] < 0) {
    //             return false;
    //         }
    //     }

    //     return true;
    // }

    // Approach 4: Optimized with fixed-size array
    // Assumes only lowercase English letters ('a'-'z')
    // Time: O(n + m)
    // Space: O(1) -> fixed 26-element array regardless of input size

    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        
        int counts[26] = {0};
        int n = s.size();

        for (char ch: s) {
            counts[ch - 'a']++;
        }
        for (char ch: t) {
            counts[ch - 'a']--;
            if (counts[ch - 'a'] < 0) {
                return false;
            }
        }
        return true;
    }
};