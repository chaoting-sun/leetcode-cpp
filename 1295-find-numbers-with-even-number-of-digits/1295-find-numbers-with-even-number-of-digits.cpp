class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int count = 0;
        for (int val: nums) {
            if (val == 0) continue;
            int numDigits = 0;
            while (val > 0) {
                val /= 10;
                numDigits++;
            }
            if (numDigits % 2 == 0) count++;
        }
        return count;
    }
};