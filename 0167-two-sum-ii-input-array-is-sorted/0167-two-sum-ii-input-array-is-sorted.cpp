class Solution {
public:
    // Approach1: Two Pointers. Maintain two pointer from left-most
    // index and right-most index, and move them toward the center
    // Time: O(n), where n is the length of numbers
    // Space: O(1)

    // vector<int> twoSum(vector<int>& numbers, int target) {
    //     int n = numbers.size();
    //     int left = 0, right = n - 1;

    //     while (left < right) {
    //         if (numbers[left] + numbers[right] < target) {
    //             left++;
    //         } else if (numbers[left] + numbers[right] > target) {
    //             right--;
    //         } else {
    //             return { left + 1, right + 1 };
    //         }
    //     }

    //     return {};
    // }

    // Approach2: Set. linearly pass through the array, recording the
    // nums[i] in the set, and check if target - nums[i] is in the set
    // Time: O(n)
    // Space: O(n)

    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int, int> map;

        for (int i = 0; i < numbers.size(); i++) {
            if (map.find(target - numbers[i]) != map.end()) {
                return { map[target - numbers[i]] + 1, i + 1 };
            }
            map.insert(make_pair(numbers[i], i));
        }
        return {};
    }

    
};