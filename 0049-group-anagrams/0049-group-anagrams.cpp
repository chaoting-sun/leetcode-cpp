// map: sorted word: [word1, word2, ...]
// iterate each string in strs
//  - sort
//  - check if it is in the map
//  - append it in map with key equal to the sorted one

// class Solution {
// public:
//     vector<vector<string>> groupAnagrams(vector<string>& strs) {
//         unordered_map<string, vector<string>> anagram_map;
//         for (string& str: strs) {
//             string sorted_str = str;
//             sort(sorted_str.begin(), sorted_str.end());
//             anagram_map[sorted_str].push_back(str);
//         }

//         vector<vector<string>> ans;
//         for (auto& [_, str_list]: anagram_map) {
//             ans.push_back(str_list);
//         }
//         return ans;
//     }
// };

// For a group of anagrams, the count of each character in each one is the same.

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagram_map;
        for (string& str: strs) {
            vector<int> freq(26);
            for (char ch: str) freq[ch - 'a']++;
            string hash;
            for (int i = 0; i < 26; i++) {
                hash += to_string(freq[i]);
                hash += "#";
            }
            anagram_map[hash].push_back(str);
        }

        vector<vector<string>> ans;
        for (auto& [_, str_list]: anagram_map) {
            ans.push_back(str_list);
        }
        return ans;
    }
};