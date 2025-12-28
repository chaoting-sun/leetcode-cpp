class Solution {
public:
    int smallestRepunitDivByK(int k) {
        int n = 0;
        int count = 0;

        while (n < k) {
            n = n * 10 + 1;
            count++;
        }

        vector<bool> seen(k + 1, false);

        while (true) {
            n = n % k;
            if (n == 0) return count;
            
            if (seen[n]) break;
            seen[n] = true;
            
            n = n * 10 + 1;
            count++;
        }

        return -1;
    }
};