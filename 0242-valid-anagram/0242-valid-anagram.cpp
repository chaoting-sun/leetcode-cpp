class Solution {
public:
    // sort both strings
    // time: O(n*lg(n)+m*lg(m)), where n = len of s, m = len of t
    // space: O(n+m)

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

    // sort both strings
    // time: O(n*lg(n)+m*lg(m)), where n = len of s, m = len of t
    // space: O(n+m)

    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;

        unordered_map<char, int> map;
        int n_distincts = 0;
        int length = s.size();

        for (int i = 0; i < length; i++) {
            if (map.find(s[i]) == map.end()) {
                map.insert({ s[i], 1 });
                n_distincts++;
            } else {
                map[s[i]]++;
            }
        }

        for (int i = 0; i < length; i++) {
            // the element in t does not exist in s
            if (map.find(t[i]) == map.end()) {
                return false;
            }

            map[t[i]]--;
            
            // t has more t[i] than s
            if (map[t[i]] < 0) {
                return false;
            }
            if (map[t[i]] == 0) {
                n_distincts--;
            }
        }

        return n_distincts == 0;
    }
};