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

    // Approach: Line Sweep

    // vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
    //     set<int> edgeSet;
    //     for (auto& building: buildings) {
    //         edgeSet.insert(building[0]);
    //         edgeSet.insert(building[1]);
    //     }
        
    //     vector<int> positions(edgeSet.begin(), edgeSet.end());
    //     vector<vector<int>> ans;

    //     for (int position: positions) {
    //         int maxHeight = 0;
    //         for (auto& building: buildings) {
    //             int l = building[0], r = building[1], h = building[2];
    //             if (l <= position && position < r) {
    //                 maxHeight = max(maxHeight, h);
    //             }
    //         }
    //         if (ans.empty() || ans.back()[1] != maxHeight) {
    //             ans.push_back({ position, maxHeight });
    //         }
    //     }

    //     return ans;
    // }

    // vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
    //     set<int> edgeSet;
    //     for (auto& building: buildings) {
    //         edgeSet.insert(building[0]);
    //         edgeSet.insert(building[1]);
    //     }
        
    //     vector<int> edges(edgeSet.begin(), edgeSet.end());

    //     unordered_map<int,int> edgeIndexMap;
    //     for (int i = 0; i < edges.size(); i++) {
    //         edgeIndexMap[edges[i]] = i;
    //     }

    //     int numEdges = edges.size();
    //     vector<int> heights(numEdges);
    //     for (auto& building: buildings) {
    //         int leftIndex = edgeIndexMap[building[0]];
    //         int rightIndex = edgeIndexMap[building[1]];
    //         int height = building[2];
    //         for (int i = leftIndex; i < rightIndex; i++) {
    //             heights[i] = max(heights[i], height);
    //         }
    //     }
        
    //     vector<vector<int>> ans;
    //     for (int i = 0; i < heights.size(); i++) {
    //         if (i == 0 || heights[i - 1] != heights[i]) {
    //             ans.push_back({ edges[i], heights[i] });
    //         }
    //     }
    //     return ans;
    // }
};
