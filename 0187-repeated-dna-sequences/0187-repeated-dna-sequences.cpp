// class Solution {
// public:
//     // Approach: Sliding Window
//     // Time: O((N-L)*L)
//     // Space: O((N-L)*L)

//     vector<string> findRepeatedDnaSequences(string s) {
//         int L = 10;
//         unordered_set<string> seen, repeatedPattern;

//         for (int i = 0; i < (int)s.size() - L + 1; i++) { // N - L
//             string pattern = s.substr(i, 10); // L
//             if (seen.count(pattern)) {
//                 repeatedPattern.insert(pattern);
//             } else {
//                 seen.insert(pattern);
//             }
//         }

//         vector<string> ans;
//         for (string pattern: repeatedPattern) ans.push_back(pattern);
//         return ans;
//     }
// };

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        const int L = 10;
        const int BITS = 2 * L;          // 20 bits for a 10-char window
        const int MASK = (1 << BITS) - 1;

        vector<string> ans;
        if ((int)s.size() < L) return ans;

        // Map nucleotide to 2-bit code.
        auto code2 = [](char ch) -> int {
            switch (ch) {
                case 'A': return 0; // 00
                case 'C': return 1; // 01
                case 'G': return 2; // 10
                case 'T': return 3; // 11
                default:  return 0; // assume valid input
            }
        };

        int rolling = 0;                 // rolling 20-bit code of current window
        unordered_set<int> seen;         // codes seen at least once
        unordered_set<int> added;        // codes already added to ans

        // Build the first (up to) 9 chars
        for (int i = 0; i < L - 1; ++i) {
            rolling = ((rolling << 2) | code2(s[i])) & MASK;
        }

        // Slide the window
        for (int i = L - 1; i < (int)s.size(); ++i) {
            rolling = ((rolling << 2) | code2(s[i])) & MASK;

            if (seen.count(rolling)) {
                if (!added.count(rolling)) {
                    ans.push_back(s.substr(i - L + 1, L));
                    added.insert(rolling);
                }
            } else {
                seen.insert(rolling);
            }
        }

        return ans;
    }
};
