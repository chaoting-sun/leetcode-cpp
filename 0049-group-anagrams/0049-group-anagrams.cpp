class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagram_map;
        for (string& str: strs) {
            string sorted_str = sort(str.begin(), str.end());
            anagram_map[sorted_str].push_back(str);
        }

        vector<vector<string>> ans;
        int idx = 0;
        for (auto [_, str_list]: anagram_map) {
            ans.push_back({});
            ans[idx++] = str_list;
        }
        return ans;
    }
};

// map: sorted word: [word1, word2, ...]
// iterate each string in strs
//  - sort
//  - check if it is in the map
//  - append it to values given sorted one in map