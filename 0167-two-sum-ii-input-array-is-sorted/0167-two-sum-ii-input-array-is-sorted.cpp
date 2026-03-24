class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        if (n < 2) return {};

        int left = 0, right = n - 1;
        while (left < right) {
            int curr = numbers[left] + numbers[right];
            if (curr > target) {
                right--;
            } else if (curr < target) {
                left++;
            } else {
                return { left + 1, right + 1 };
            }
        }

        return {};
    }
};
