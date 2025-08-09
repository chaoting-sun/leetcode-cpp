class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> counts;
        for (char c: s1) counts[c]++;
        unordered_map<char, int> curr(counts);
        
        int n = s2.size();
        int left = 0, right = 0;

        while (right < n) {
            // neglect all unrelated characters
            if (curr.find(s2[right]) == curr.end()) {
                curr = counts;
                right++;
                left = right;
                continue;
            }

            curr[s2[right]]--;

            // if the number of the character in the substring is more than that in the s2
            // then move the left forward
            while (curr[s2[right]] < 0) {
                if (curr.find(s2[left]) != curr.end()) {
                    curr[s2[left]]++;
                }
                left++;
            }

            int n_left = 0;
            for (auto c: curr) n_left += c.second;
            if (n_left == 0) return true;

            right++;
        }

        return false;
    }
};