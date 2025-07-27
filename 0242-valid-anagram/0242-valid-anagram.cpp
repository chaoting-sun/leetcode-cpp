class Solution {
public:
    // sort both strings
    // time: O(n*lg(n)+m*lg(m)), where n = len of s, m = len of t
    // space: O(1) -> 26 elements at most

    // bool isAnagram(string s, string t) {
    //     if (s.size() != t.size()) return false;
        
    //     string s_copy = s;
    //     string t_copy = t;

    //     sort(s_copy.begin(), s_copy.end());
    //     sort(t_copy.begin(), t_copy.end());

    //     for (int i = 0; i < s.size(); i++) {
    //         if (s_copy[i] != t_copy[i]) {
    //             return false;
    //         }
    //     }

    //     return true;
    // }

    // Counter: counting the number of characters in s first,
    // and then do a for loop on t, decrement the count of the same
    // character appearing in t.
    // time: O(n+m), where n = len of s, m = len of t
    // space: O(1) -> 26 element at most

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

    // Simplified Counter: we do not have to check if s contains
    // extra characters not in "t" because an extra character in t
    // comes at the expense of an extra character in s.
    // time: O(n+m), where n = len of s, m = len of t
    // space: O(distinct number of characters in s)

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

    // Save counts in array
    // time: O(n*lg(n)+m*lg(m)), where n = len of s, m = len of t
    // space: O(1) -> 26 elements at most

    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        
        int counts[26] = {0};
        int n = s.size();

        for (int i = 0; i < n; i++) {
            counts[s[i]-'a']++;
        }
        for (int i = 0; i < n; i++) {
            counts[t[i]-'a']--;
            if (counts[t[i]-'a'] < 0) {
                return false;
            }
        }
        return true;
    }
};