class Solution {
public:
    // Approach: Stack
    // Time: O(n)
    // Space: O(1)

    // int minLength(string s) {
    //     string ans;
    //     for (char c: s) {
    //         if (!ans.empty() &&
    //             (ans.back() == 'A' && c == 'B' ||
    //              ans.back() == 'C' && c == 'D')) {
    //             ans.pop_back();
    //         } else {
    //             ans.push_back(c);
    //         }
    //     }
    //     return ans.size();
    // }

    // Approach: Two Pointers
    // Time: O(n)
    // Space: O(1)

    int minLength(string s) {
        int end = 0;
        for (int i = 0; i < s.size(); i++) {
            if (end > 0 &&
                (s[end - 1] == 'A' && s[i] == 'B' ||
                 s[end - 1] == 'C' && s[i] == 'D')) {
                end--;
            } else {
                s[end] = s[i];
                end++;
            }
        }
        return end;
    }
};