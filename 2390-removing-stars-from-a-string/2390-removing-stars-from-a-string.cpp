class Solution {
public:
    // Approach: stack
    // Time: O(n)
    // Space: O(n)

    // string removeStars(string s) {
    //     string ans;
    //     for (char c: s) {
    //         if (!ans.empty() && c == '*') {
    //             ans.pop_back();
    //         } else {
    //             ans.push_back(c);
    //         }
    //     }
    //     return ans;
    // }

    // Approach: Two Pointers
    // Time: O(n)
    // Space: O(n)

    string removeStars(string s) {
        int j = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '*') {
                j--;
            } else {
                s[j] = s[i];
                j++;
            }
        }

        return s.substr(0, j);
    }
};
