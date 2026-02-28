// The naive method is
// we store the count of each element in a hash map
// then, we sort by the count and get the top k elements
// this cost O(NlogN) in worst case

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (int val: nums) freq[val]++;

        vector<pair<int,int>> val_freq;
        for (auto [val, f]: freq) val_freq.push_back({ val, f });
        sort(val_freq.begin(), val_freq.end(), [](pair<int,int>& p1, pair<int,int>& p2) {
            return p1.second > p2.second;
        });

        vector<int> ans;
        for (int i = 0; i < k; i++) ans.push_back(val_freq[i].first);

        return ans;
    }
};

// test case: nums = [1,1,2], k = 1
// freq = { 1: 2, 2: 1 }
// val_freq = [{1,2}, {2,1}]
// sort -> val_freq = [{1,2}, {2,1}]
// ans = [1]
// < returns [1]