// The naive method is
// we store the count of each element in a hash map
// then, we sort by the count and get the top k elements
// this cost O(NlogN) in worst case

// class Solution {
// public:
//     vector<int> topKFrequent(vector<int>& nums, int k) {
//         unordered_map<int, int> freq;
//         for (int val: nums) freq[val]++;

//         vector<pair<int,int>> val_freq;
//         for (auto [val, f]: freq) val_freq.push_back({ val, f });
//         sort(val_freq.begin(), val_freq.end(), [](pair<int,int>& p1, pair<int,int>& p2) {
//             return p1.second > p2.second;
//         });

//         vector<int> ans;
//         for (int i = 0; i < k; i++) ans.push_back(val_freq[i].first);

//         return ans;
//     }
// };

// test case: nums = [1,1,2], k = 1
// freq = { 1: 2, 2: 1 }
// val_freq = [{1,2}, {2,1}]
// sort -> val_freq = [{1,2}, {2,1}]
// ans = [1]
// < returns [1]

// The problem asks "k most frequent elements", which is a hint for using heap
// We still save the count into freq
// then push { count, number } into a min heap, sorted by count
// we keep the min heap in the size of k. If it's larger than k, then we pop it.
// The final ones in the min heap are the k most frequent elements.
// The time complexity is O(NlogK)

// class Solution {
// public:
//     vector<int> topKFrequent(vector<int>& nums, int k) {
//         unordered_map<int, int> freq;
//         for (int val: nums) freq[val]++;

//         priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
//         for (auto [v, f]: freq) {
//             pq.push({ f, v });
//             if (pq.size() > k) pq.pop();
//         }

//         vector<int> ans;
//         while (!pq.empty()) {
//             ans.push_back(pq.top().second);
//             pq.pop();
//         }

//         return ans;
//     }
// };

// bucket numbers by frequency

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        if (k > n) return {};
        
        unordered_map<int, int> freq;
        for (int val: nums) freq[val]++;

        vector<vector<int>> bucket(n + 1);
        for (auto [v, f]: freq) {
            bucket[f].push_back(v);
        }

        vector<int> ans;
        for (int i = n; i >= 1; i--) {
            for (int val: bucket[i]) {
                ans.push_back(val);
                if (ans.size() == k) return ans;
            }
        }

        return ans;
    }
};

// test case: nums=[1,1,1,2,2,3], k=2
// trace:
// n = 6
// freq = { 1: 3, 2: 2, 3: 1 }
// bucket[3] = [1], bucket[2] = [2], bucket[1] = [3]
// ans = []
// i = 6, ..., i = 3: ans = [1]
// i = 2: ans = [1,2]
