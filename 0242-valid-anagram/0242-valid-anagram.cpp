class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        
        string s_copy = s;
        string t_copy = t;

        sort(s_copy.begin(), s_copy.end());
        sort(t_copy.begin(), t_copy.end());

        for (int i = 0; i < s.size(); i++) {
            if (s_copy[i] != t_copy[i]) {
                return false;
            }
        }

        return true;
    }
};