using ll = long long;

class Solution {
public:
    bool isFeasible(vector<int>& ranks, int cars, ll time) {
        ll repairedCars = 0;
        for (int r: ranks) {
            repairedCars += floor(sqrt(time / r));
        }
        return repairedCars >= cars;
    }
    
    long long repairCars(vector<int>& ranks, int cars) {
        int minRank = INT_MAX;
        for (int r: ranks) minRank = min(minRank, r);
        ll left = 1;
        ll right = minRank * cars * cars;
        while (left < right) {
            ll mid = left + (right - left) / 2;
            if (isFeasible(ranks, cars, mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return right;
    }
};
