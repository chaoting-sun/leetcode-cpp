class Solution {
public:
    long long getKey(int x, int y) {
        return ((long long)x << 32) ^ ((long long)y - INT_MIN);
    }

    bool isRectangleCover(vector<vector<int>>& rectangles) {
        int minX = INT_MAX, minY = INT_MAX;
        int maxX = INT_MIN, maxY = INT_MIN;
        long long area = 0;
        unordered_set<long long> points;
        for (auto& rect: rectangles) {
            long long p1 = getKey(rect[0], rect[1]);
            long long p2 = getKey(rect[0], rect[3]);
            long long p3 = getKey(rect[2], rect[1]);
            long long p4 = getKey(rect[2], rect[3]);
            for (auto& p: { p1, p2, p3, p4 }) {
                if (points.count(p)) {
                    points.erase(p);
                } else {
                    points.insert(p);
                }
            }
            minX = min(minX, rect[0]);
            maxX = max(maxX, rect[2]);
            minY = min(minY, rect[1]);
            maxY = max(maxY, rect[3]);
            area += (long long)(rect[2] - rect[0]) * (rect[3] - rect[1]);
        }
        if (points.size() != 4) return false;
        if (!points.count(getKey(minX, minY)) ||
            !points.count(getKey(minX, maxY)) ||
            !points.count(getKey(maxX, minY)) ||
            !points.count(getKey(maxX, maxY))) {
            return false;
        }
        return area == (long long)(maxX - minX) * (maxY - minY);
    }
};