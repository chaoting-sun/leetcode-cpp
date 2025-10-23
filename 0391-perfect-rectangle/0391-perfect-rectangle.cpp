class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        int minX = INT_MAX, minY = INT_MAX;
        int maxX = INT_MIN, maxY = INT_MIN;
        long long area = 0;
        set<pair<int,int>> edges;
        for (auto& rect: rectangles) {
            pair<int,int> p1 = { rect[0], rect[1] };
            pair<int,int> p2 = { rect[0], rect[3] };
            pair<int,int> p3 = { rect[2], rect[1] };
            pair<int,int> p4 = { rect[2], rect[3] };
            for (auto& p: { p1, p2, p3, p4 }) {
                if (edges.count(p)) {
                    edges.erase(p);
                } else {
                    edges.insert(p);
                }
            }
            minX = min(minX, rect[0]);
            maxX = max(maxX, rect[2]);
            minY = min(minY, rect[1]);
            maxY = max(maxY, rect[3]);
            area += (long long)(rect[2] - rect[0]) * (rect[3] - rect[1]);
        }
        if (edges.size() != 4 ||
            !edges.count({ minX, minY }) ||
            !edges.count({ minX, maxY }) ||
            !edges.count({ maxX, minY }) ||
            !edges.count({ maxX, maxY })) {
            return false;
        }
        return area == (long long)(maxX - minX) * (maxY - minY);
    }
};