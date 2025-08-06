class Solution {
public:
    // Intuition: when h is very large, k can be very small, with the minimum value 1;
    // when h is very small (h = piles.length), k should be the maximum value in the
    // piles, which at most 10^9. so we can search the smallest k between [1, 10^9].
    // Time: O(log(10^9))
    // Space: O(1)

    int computeTime(vector<int>& piles, int k) {
        int n = piles.size();
        int time = 0;
        for (int i = 0; i < n; i++) {
            time += piles[i] / k;
            time += piles[i] % k == 0 ? 0 : 1;
        }
        return time;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1, right = 1e9;

        while (left < right) {
            int mid = left + (right - left) / 2;
            int time = computeTime(piles, mid);
            if (time > h) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        return right;
    }
};
