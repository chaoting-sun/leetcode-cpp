class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        set<int> edgeSet;
        for (auto& building: buildings) {
            edgeSet.insert(building[0]);
            edgeSet.insert(building[1]);
        }
        
        vector<int> edges(edgeSet.begin(), edgeSet.end());

        unordered_map<int,int> edgeIndexMap;
        for (int i = 0; i < edges.size(); i++) {
            edgeIndexMap[edges[i]] = i;
        }

        int numEdges = edges.size();
        vector<int> heights(numEdges);
        for (auto& building: buildings) {
            int leftIndex = edgeIndexMap[building[0]];
            int rightIndex = edgeIndexMap[building[1]];
            int height = building[2];
            for (int i = leftIndex; i < rightIndex; i++) {
                heights[i] = max(heights[i], height);
            }
        }
        
        vector<vector<int>> ans;
        for (int i = 0; i < heights.size(); i++) {
            if (i == 0 || heights[i - 1] != heights[i]) {
                ans.push_back({ edges[i], heights[i] });
            }
        }
        return ans;
    }
};
