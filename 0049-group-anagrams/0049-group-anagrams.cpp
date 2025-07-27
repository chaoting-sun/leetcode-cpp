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
    
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> records(0);

        for (string& s: strs) {
            vector<int> counts(26);
            for (char ch: s) {
                counts[ch - 'a'] += 1;
            }
            string k{};
            for (int i = 0; i < 26; i++) {
                k += to_string(counts[i]);
                if (i < 25) k += "#";
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
