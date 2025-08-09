class Solution {
public:
    // Approach: sliding window
    // Time: O(m+n) = O(n)
    //  - O(m): store the character counts in s1 in map
    //  - O(n): loop the s2
    // Space: O(26) = O(1)

    // bool checkInclusion(string s1, string s2) {
    //     unordered_map<char, int> counts;
    //     for (char c: s1) counts[c]++;
    //     unordered_map<char, int> curr(counts);
        
    //     int n = s2.size();
    //     int left = 0, right = 0;

    //     while (right < n) {
    //         // reset 'curr' to counts if we find a character not in curr because the window cannot form a matching permutation
    //         if (curr.find(s2[right]) == curr.end()) {
    //             curr = counts;
    //             right++;
    //             left = right;
    //             continue;
    //         }

    //         curr[s2[right]]--;

    //         // if the number of the character in the substring is more than that in the s2
    //         // then move the left forward
    //         while (curr[s2[right]] < 0) {
    //             if (curr.find(s2[left]) != curr.end()) {
    //                 curr[s2[left]]++;
    //             }
    //             left++;
    //         }

    //         int n_left = 0;
    //         for (auto c: curr) n_left += c.second;
    //         if (n_left == 0) return true;

    //         right++;
    //     }

    //     return false;
    // }

    // Simplified Version
    // Time: O(m+n) = O(n)
    // Space: O(26) = O(1)

    bool checkInclusion(string s1, string s2) {
        vector<int> counts1(26), counts2(26);
        for (char c: s1) counts1[c - 'a']++;
        
        int left = 0, right = 0;

        while (right < s2.size()) {
            counts2[s2[right] - 'a']++;

            int curr_len = right - left + 1;

            if (curr_len == s1.size() && counts1 == counts2) {
                return true;
            }

            if (curr_len == s1.size()) {
                counts2[s2[left] - 'a']--;
                left++;
                right++;
            } else {
                right++;
            }
        }

        return false;
    }
};