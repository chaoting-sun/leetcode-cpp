class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> records(0);

        for (string& s: strs) {
            string t = s;
            sort(t.begin(), t.end());
            if (records.find(t) == records.end()) {
                records.insert({ t, vector<string>{} });
            }
            records[t].push_back(s);
        }

        vector<vector<string>> ans(0);
        for (auto& rec: records) {
            ans.push_back(rec.second);
        }

        return ans;
    }
};
