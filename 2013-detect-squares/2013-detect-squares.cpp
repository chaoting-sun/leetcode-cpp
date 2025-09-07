class DetectSquares {
public:
    map<pair<int,int>, int> points;

    DetectSquares() {
        
    }
    
    void add(vector<int> point) {
        points[{ point[0], point[1] }]++;
    }
    
    int count(vector<int> point) {
        int x1 = point[0], y1 = point[1];
        int ans = 0;
        
        for (auto [p, _]: points) {
            int x2 = p.first, y2 = p.second;

            // avoid the same point
            if (x1 == x2 && y1 == y2) continue;
            // search for the diagonal point
            if (abs(x2 - x1) != abs(y2 - y1)) continue;
            // check if the other 2 points exist
            if (!points.count({ x1, y2 }) || !points.count({ x2, y1 })) continue;
            ans += points[{ x2, y2 }] * points[{ x1, y2 }] * points[{ x2, y1 }];
        }

        return ans;
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */