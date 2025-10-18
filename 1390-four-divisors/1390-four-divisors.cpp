class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int ans = 0;
        for (int n: nums) {
            int count = 0;
            int totalSum = 0;
            for (int i = 1; i * i <= n; i++) {
                if (n % i == 0) {
                    count += 2;
                    totalSum += i + n / i;
                    if (i * i == n) {
                        count--;
                        totalSum -= i;
                    }
                }
            }
            if (count == 4) {
                ans += totalSum;
            }
        }
        return ans;
    }
};