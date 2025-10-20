class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> ans;
        int i = 0, j = 0;
        while (i < firstList.size() && j < secondList.size()) {
            int l1 = firstList[i][0], r1 = firstList[i][1];
            int l2 = secondList[j][0], r2 = secondList[j][1];
            // not overlapped
            if (r1 < l2 || r2 < l1) {
                if (r1 < r2) i++;
                else j++;
                continue;
            }
            ans.push_back({ max(l1, l2), min(r1, r2) });
            if (r1 < r2) i++;
            else j++;
        }
        return ans;
    }
};

// L1 = [l1, r1]
// L2 = [l2, r2]

// not overlap -> r1 < l2 || r2 < l1
// overlap -> segment = max(l1, l2), max(r1, r2)