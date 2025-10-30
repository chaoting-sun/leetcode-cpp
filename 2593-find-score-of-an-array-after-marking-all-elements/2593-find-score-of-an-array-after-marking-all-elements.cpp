class Solution {
public:
    // [3,2,1,10]

    long long findScore(vector<int>& nums) {
        int n = nums.size();
        long long score = 0;
        int lastEnd = -1;
        int i = 1;
        while (i < n) {
            if (nums[i - 1] <= nums[i]) {
                int j = i - 1;
                while (lastEnd < j) {
                    score += nums[j];
                    j -= 2;
                }
                lastEnd = i;
                i += 2;
            } else {
                i++;
            }
        }
        for (int i = n - 1; i > lastEnd; i -= 2) {
            score += nums[i];
        }
        return score;
    }

    // long long findScore(vector<int>& nums) {
    //     int n = nums.size();
    //     stack<int> stk;
    //     long long score = 0;
    //     for (int i = 0; i < n; i++) {
    //         if (!stk.empty() && stk.top() <= nums[i]) {
    //             while (!stk.empty()) {
    //                 score += stk.top();
    //                 stk.pop();
    //                 if (!stk.empty()) stk.pop();
    //             }
    //             continue;
    //         }
    //         stk.push(nums[i]);
    //     }
    //     while (!stk.empty()) {
    //         score += stk.top();
    //         stk.pop();
    //         if (!stk.empty()) stk.pop();
    //     }

    //     return score;
    // }

    // long long findScore(vector<int>& nums) {
    //     int n = nums.size();
    //     vector<bool> marked(n, false);
    //     priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    //     long long score = 0;
    //     for (int i = 0; i < n; i++) {
    //         pq.push({ nums[i], i });
    //     }
    //     while (!pq.empty()) {
    //         while (!pq.empty() && marked[pq.top().second]) {
    //             pq.pop();
    //         }
    //         if (pq.empty()) break;

    //         auto [val, idx] = pq.top();
    //         pq.pop();
    //         score += val;
    //         marked[idx] = true;
    //         if (idx > 0) marked[idx - 1] = true;
    //         if (idx < n - 1) marked[idx + 1] = true;
    //     }
    //     return score;
    // }
};