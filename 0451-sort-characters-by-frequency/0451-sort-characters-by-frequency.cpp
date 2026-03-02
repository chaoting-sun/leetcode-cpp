// class Solution {
// public:
//     string frequencySort(string s) {
//         unordered_map<char, int> freq;
//         for (char c: s) freq[c]++;

//         vector<pair<char, int>> char_freq;
//         for (auto [c, f]: freq) {
//             char_freq.push_back({ c, f });
//         }

//         sort(char_freq.begin(), char_freq.end(), [](pair<char,int>& f1, pair<char, int>& f2) {
//             return f1.second > f2.second;
//         });

//         string ans;
//         for (auto [c, f]: char_freq) {
//             while (f--) ans += c; 
//         }
//         return ans;
//     }
// };

// test case: s = "tree"
// trace:
// freq = { t: 1, r: 1, e 2 }
// char_freq = [(t,1), (r,1), (e,2)]
// sorted -> char_freq = [(e,2), (t,1), (r,1)]
// ans = eetr

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;
        int max_freq = 0;
        for (char c: s) {
            freq[c]++;
            max_freq = max(max_freq, freq[c]);
        }

        vector<vector<char>> bucket(max_freq + 1);
        
        for (auto [c, f]: freq) {
            bucket[f].push_back(c);
        }

        string ans;
        for (int f = max_freq; f >= 1; f--) {
            for (char c: bucket[f]) {
                ans += string(f, c);
            }
        }
        return ans;
    }
};

// test case: s = "tree"
// trace:
// freq = { t: 1, r: 1, e: 2 }
// bucket = [[], [t, r], [e], [], []]
// ans = eetr