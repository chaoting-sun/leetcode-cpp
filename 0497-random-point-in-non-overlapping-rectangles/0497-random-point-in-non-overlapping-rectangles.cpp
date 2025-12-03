using ll = long long;

class Solution {
private:
    mt19937_64 rng;
    uniform_int_distribution<ll> uni;
    vector<ll> prefix;
    vector<vector<int>> rects;

public:
    Solution(vector<vector<int>>& rects) {
        this->rects = move(rects);
        prefix.reserve(rects.size());

        ll total_area = 0;
        for (const auto& rect: this->rects) {
            ll width = rect[2] - rect[0] + 1;
            ll height = rect[3] - rect[1] + 1;
            total_area += width * height;
            prefix.push_back(total_area);
        }

        random_device rd;
        rng = mt19937_64(rd());
        uni = uniform_int_distribution<ll>(1, prefix.back());
    }

    vector<int> pick() {
        ll target = uni(rng);

        int left = 0, right = prefix.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (prefix[mid] >= target) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        const auto& r = rects[right];
        uniform_int_distribution<int> x_dist(r[0], r[2]);
        uniform_int_distribution<int> y_dist(r[1], r[3]);
        return { x_dist(rng), y_dist(rng) };
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */