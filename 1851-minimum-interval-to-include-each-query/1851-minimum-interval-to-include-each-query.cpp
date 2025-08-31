struct Compare {
    bool operator()(pair<int,int> &a, pair<int,int> &b) const {
        return a.first > b.first;
    }
};

class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        int ni = intervals.size(), nq = queries.size();
        
        sort(intervals.begin(), intervals.end(), [&](vector<int> &a, vector<int> &b) {
            return a[0] < b[0];
        });

        vector<int> sorted_queries = queries;
        sort(sorted_queries.begin(), sorted_queries.end());
        priority_queue<pair<int,int>, vector<pair<int,int>>, Compare> pq; // size, interval end

        int j = 0;
        unordered_map<int, int> query_ans;

        for (int i = 0; i < nq; i++) {
            int q = sorted_queries[i];
            while (j < ni && intervals[j][0] <= q) {
                pq.push({ intervals[j][1] - intervals[j][0] + 1, intervals[j][1] });
                j++;
            }

            while (!pq.empty() && pq.top().second < q) {
                pq.pop();
            }

            query_ans[q] = pq.empty() ? -1 : pq.top().first;
        }

        vector<int> ans(nq);
        for (int i = 0; i < nq; i++) {
            ans[i] = query_ans[queries[i]];
        }

        return ans;
    }
};