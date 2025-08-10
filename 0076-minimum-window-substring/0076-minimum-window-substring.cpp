class Solution {
public:
    // Approach: Sliding Window
    // count the characters numbers of t in a hashmap (t_counts) first. then loop s and count the character numbers in another hashmap (s_counts).
    // we also maintain two variables: have and need:
    //  - "have" is the number of distinct characters we have found, in which the number of each character is more than that in the t_counts in [left, right]
    //  - "need" is the total number of distinct characters we need to found. ex: if t = "abccc" -> need = 3
    // Time: O(len(s) + len(t))
    // Space: O(1)

    string minWindow(string s, string t) {
        unordered_map<char, int> s_counts, t_counts;
        for (char ch: t) t_counts[ch]++;

        int left = 0, right = 0;
        int n = s.size();
        int have = 0, need = t_counts.size();
        int min_left = 0, min_len = INT_MAX;

        while (right < n) {
            s_counts[s[right]]++;

            // if the count of the current character (ch) is equal to t, then we have found enough number of ch that t_counts needs
            if (t_counts.find(s[right]) != t_counts.end() && s_counts[s[right]] == t_counts[s[right]]) {
                have++;
            }

            // if the current interval is a valid substring, then move left toward step by step until the interval is invalid
            // also, we update min_len to search for the min substring length
            while (have == need) {
                if ((right - left + 1) < min_len) {
                    min_len = right - left + 1;
                    min_left = left;
                }

                s_counts[s[left]]--;
                if (t_counts.find(s[left]) != t_counts.end() && s_counts[s[left]] < t_counts[s[left]]) {
                    have--;
                }
                left++;
            }
            right++;
        }

        if (min_len == INT_MAX) return "";
        return s.substr(min_left, min_len);
    }
};