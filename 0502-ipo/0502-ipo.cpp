class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        vector<pair<int,int>> projects(n);
        for (int i = 0; i < n; i++) {
            projects[i] = { profits[i], capital[i] };
        }
        sort(projects.begin(), projects.end(), [](pair<int,int>& a, pair<int,int>& b) {
            return a.second < b.second;
        });
        priority_queue<int> pq; // profit[i]
        int projIdx = 0;
        while (k--) {
            while (projIdx < n && w >= projects[projIdx].second) {
                pq.push(projects[projIdx].first);
                projIdx++;
            }
            if (pq.empty()) break;
            w += pq.top();
            pq.pop();
        }
        return w;
    }
};