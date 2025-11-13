// [[7,0], [7,1],[4,4],[5,0],[6,1],[5,2]]

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), [](vector<int>& p1, vector<int>& p2) {
            if (p1[0] != p2[0]) return p1[0] > p2[0];
            return p1[1] < p2[1];
        });
        queue<vector<int>> q;
        for (vector<int>& p: people) {
            queue<vector<int>> nextQ;
            for (int i = 0; i < p[1]; i++) {
                nextQ.push(q.front());
                q.pop();
            }
            nextQ.push(p);
            while (!q.empty()) {
                nextQ.push(q.front());
                q.pop();
            }
            q.swap(nextQ);
        }
        vector<vector<int>> ans;
        ans.reserve(people.size());
        while (!q.empty()) {
            ans.push_back(q.front());
            q.pop();
        }
        return ans;
    }
};