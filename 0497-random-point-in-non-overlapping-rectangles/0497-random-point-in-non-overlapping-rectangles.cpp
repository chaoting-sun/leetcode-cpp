using ll = long long;

class Solution {
private:
    mt19937_64 rng;
    uniform_int_distribution<ll> uni;
    vector<ll> prefix;
    vector<vector<int>> rects;

    ll getNumPoints(vector<int>& rect) {
        ll width = rect[2] - rect[0] + 1;
        ll height = rect[3] - rect[1] + 1;
        return width * height;
    }

    ll getRandNumber() {
        return uni(rng);
    }
public:
    Solution(vector<vector<int>>& rects) {
        this->rects = rects;

        prefix.resize(rects.size());
        prefix[0] = getNumPoints(rects[0]);
        for (int i = 1; i < rects.size(); i++) {
            prefix[i] = prefix[i - 1] + getNumPoints(rects[i]);
        }
        random_device rd;
        rng = mt19937_64(rd());
        uni = uniform_int_distribution<ll>(1, prefix.back());
    }

    vector<int> pick() {
        ll target = getRandNumber();

        int left = 0, right = prefix.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (prefix[mid] >= target) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        ll k = (right == 0 ? target : target - prefix[right - 1]) - 1;
        int width = rects[right][2] - rects[right][0] + 1;
        int col = k % width;
        int row = k / width;
        return { rects[right][0] + col, rects[right][1] + row };
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */