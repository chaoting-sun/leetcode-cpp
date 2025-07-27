class Solution {
public:
    // Approach 1: Categorize by Sorted String
    // time: O(n*(k*logk)) -> n is the length of strs and k is the maximum length of the strings in strs
    // space: O(n*k)

    // vector<vector<string>> groupAnagrams(vector<string>& strs) {
    //     unordered_map<string, vector<string>> records(0);

    //     for (string& s: strs) {
    //         string t = s;
    //         sort(t.begin(), t.end());
    //         if (records.find(t) == records.end()) {
    //             records.insert({ t, vector<string>{} });
    //         }
    //         records[t].push_back(s);
    //     }

    //     vector<vector<string>> ans(0);
    //     for (auto& rec: records) {
    //         ans.push_back(rec.second);
    //     }

    //     return ans;
    // }

    // Approach 2: Categorize by Count
    // Intuition: because the strs[i] consists of lowercase english letters,
    // we can map each str to a character count represented by an array of 26 slots.
    // If two strings are anagram, then their array will be the same.
    // Time: O(n*k), where n is the strs length, while k is the maximum length of the elements in strs
    // Space: O(n*k) -> the total data in records
    
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> records(0);

        for (string& s: strs) {
            vector<int> counts(26);
            for (char ch: s) {
                counts[ch - 'a'] += 1;
            }
            string k = "";
            for (int i = 0; i < 26; i++) {
                k += to_string(counts[i]);
                if (i < 25) k += "#";
            }
            
            if (records.find(k) == records.end()) {
                records.insert({ k, vector<string>() });
            }
            records[k].push_back(s);
        }

        vector<vector<string>> ans(0);
        for (auto& rec: records) {
            ans.push_back(rec.second);
        }

        return ans;
    }
};
