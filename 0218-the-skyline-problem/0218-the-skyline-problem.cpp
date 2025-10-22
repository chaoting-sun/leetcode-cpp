class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        set<int> edgeSet;
        for (auto& building: buildings) {
            edgeSet.insert(building[0]);
            edgeSet.insert(building[1]);
        }
        
        vector<int> positions(edgeSet.begin(), edgeSet.end());
        vector<vector<int>> ans;
        priority_queue<pair<int,int>> maxHeap; // height, right side
        sort(buildings.begin(), buildings.end(), [](vector<int>& b1, vector<int> b2) {
            return b1[0] < b2[0];
        });

        int idx = 0;
        for (int position: positions) {
            while (idx < buildings.size() && buildings[idx][0] <= position) {
                int right = buildings[idx][1], height = buildings[idx][2];
                maxHeap.push({ height, right });
                idx++;
            }
            while (!maxHeap.empty() && maxHeap.top().second <= position) {
                maxHeap.pop();
            }
            int maxHeight = maxHeap.empty() ? 0 : maxHeap.top().first;
            if (ans.empty() || ans.back()[1] != maxHeight) {
                ans.push_back({ position, maxHeight });
            }
        }
        return ans;
    }
};
