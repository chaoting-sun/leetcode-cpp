class Solution {
public:
    // Approach1: count the elements and sort by array
    // time: O(n*log(n))
    // space: O(n)

    // vector<int> topKFrequent(vector<int>& nums, int k) {
    //     unordered_map<int, int> count;
    //     for (int n: nums) {
    //         if (count.find(n) == count.end()) {
    //             count.insert({ n, 1 });
    //         } else {
    //             count[n]++;
    //         }
    //     }

    //     vector<pair<int, int>> count_arr;
    //     for (auto c: count) {
    //         count_arr.push_back(make_pair(c.first, c.second));
    //     }

    //     sort(count_arr.begin(), count_arr.end(), [&](pair<int, int>& c1, pair<int, int>& c2){
    //         return c1.second > c2.second;
    //     });

    //     vector<int> ans;
    //     for (int i = 0; i < k; i++) {
    //         ans.push_back(count_arr[i].first);
    //     }

    //     return ans;
    // }

    // Approach2.1: count the elements and sort by priority queue
    // time: O(n+n*log(n)+k)=O(n*log(n)), where n is the length of nums
    // space: O(n)

    // vector<int> topKFrequent(vector<int>& nums, int k) {
    //     unordered_map<int, int> count;
    //     for (int n: nums) {
    //         if (count.find(n) == count.end()) {
    //             count.insert({ n, 1 });
    //         } else {
    //             count[n]++;
    //         }
    //     }

    //     priority_queue<pair<int, int>> pq;
    //     for (auto c: count) {
    //         pq.push(make_pair(c.second, c.first));
    //     }

    //     vector<int> ans;
    //     for (int i = 0; i < k; i++) {
    //         ans.push_back(pq.top().second);
    //         pq.pop();
    //     }

    //     return ans;
    // }

    // Approach2.2: count the elements and sort by priority queue
    // time: O(n+n*log(n)+k)=O(n*log(n)), where n is the length of nums
    // space: O(n)

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        for (int n: nums) {
            if (count.find(n) == count.end()) {
                count.insert({ n, 1 });
            } else {
                count[n]++;
            }
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (auto c: count) {
            pq.push(make_pair(c.second, c.first));
            if (pq.size() > k) pq.pop();
        }

        vector<int> ans;
        for (int i = 0; i < k; i++) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }

    // vector<int> topKFrequent(vector<int>& nums, int k) {
    //     unordered_map<int, int> count;
    //     int max_count = 0;
    //     for (int n: nums) {
    //         count[n]++;
    //         max_count = max(max_count, count[n]);
    //     }

    //     vector<vector<int>>count_arr(max_count+1);
    //     for (auto& c: count) {
    //         count_arr[c.second].push_back(c.first);
    //     }

    //     vector<int> ans;
    //     int n_left = k;
    //     for (int i = max_count; i >= 0; i--) {
    //         int j = 0;
    //         for (int j = 0; j < count_arr[i].size(); j++) {
    //             ans.push_back(count_arr[i][j]);
    //             n_left--;
    //             if (n_left == 0) break;
    //         }
    //         if (n_left == 0) break;
    //     }
    //     return ans;
    // }
};