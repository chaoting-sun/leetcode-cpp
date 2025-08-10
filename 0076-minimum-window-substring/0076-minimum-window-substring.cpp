class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> s_counts, t_counts;
        for (char ch: t) t_counts[ch]++;

        int left = 0, right = 0;
        int n = s.size();
        int min_len = INT_MAX, min_right = -1, min_left = -1;

        while (right < n) {
            s_counts[s[right]]++;

            if (isValid(s_counts, t_counts)) {
                // update min interval
                if (right - left + 1 < min_len) {
                    min_left = left;
                    min_right = right;
                }

                // move left to the next character that is in t
                if (left < right && t_counts.find(s[left]) != t_counts.end()) {
                    left++;
                    s_counts[s[left]]--;
                }
                while (left < right && t_counts.find(s[left]) == t_counts.end()) {
                    left++;
                    s_counts[s[left]]--;
                }
            }

            right++;
        }

        // check if valid answer exists
        if (min_right == -1) return "";
        return s.substr(min_left, min_right - min_left + 1);
    }

    bool isValid(unordered_map<char, int> &s_counts, unordered_map<char, int> &t_counts) {
        for (auto t: t_counts) {
            if (s_counts.find(t.first) == s_counts.end() || s_counts[t.first] < t_counts[t.first]) {
                return false;
            }
        }
        return true;
    }
};