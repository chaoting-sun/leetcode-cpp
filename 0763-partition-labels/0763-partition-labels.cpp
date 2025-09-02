class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.size();
        if (n == 0) return {};
        
        unordered_map<int, int> min_ids, max_ids;

        for (int i = 0; i < n; i++) {
            char c = s[i];
            if (!min_ids.count(c)) min_ids[c] = i;
            max_ids[c] = i;
        }

        vector<int> ans;

        int start = 0;
        while (start < n) {
            int end = max_ids[s[start]];
            int idx = start;
            while (idx < end) {
                idx++;
                end = max(end, max_ids[s[idx]]);
            }
            ans.push_back(end - start + 1);
            start = end + 1;
        }

        return ans;
    }
};