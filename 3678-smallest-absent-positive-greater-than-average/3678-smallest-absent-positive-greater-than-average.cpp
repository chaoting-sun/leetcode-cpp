// Approach: Hash Table
// Time: O(n)
// Space: O(n)

class Solution {
public:
    int smallestAbsent(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        unordered_set<int> present_numbers;

        // calculate sum and record all numbers
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            present_numbers.insert(nums[i]);
        }

        int average = sum / n;
        int candidate = max(average + 1, 1);

        // find the smallest absent positive number > average
        while (true) {
            if (!present_numbers.count(candidate)) {
                return candidate;
            }
            candidate++;
        }

        return -1; // unreachable, but keeps the compiler happy
    }
};