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

    // Approach2: Hash Map. linearly pass through the array, recording the
    // nums[i] in the set, and check if target - nums[i] is in the set
    // Time: O(n), where n is the length of numbers
    // Space: O(n)

    // vector<int> twoSum(vector<int>& numbers, int target) {
    //     unordered_map<int, int> map;

    //     for (int i = 0; i < numbers.size(); i++) {
    //         if (map.find(target - numbers[i]) != map.end()) {
    //             return { map[target - numbers[i]] + 1, i + 1 };
    //         }
    //         map.insert(make_pair(numbers[i], i));
    //     }
    //     return { -1, -1 };
    // }

    // Approach3: Binary Search. loop from 0 to n - 1, and do binary search for
    // target - numbers[i] for the rest elements between the range [i + 1, n - 1].
    // Time: O(n*log(n)). O(log(n-1)+log(n-2)+...log(1)) <= O(n*log(n-1)) <= O(n*log(n))
    // Space: O(1)

    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();

        for (int i = 0; i < n - 1; i++) {
            int to_find = target - numbers[i];
            
            int left = i + 1;
            int right = n - 1;
            
            while (left <= right) {
                int mid = (left + right) / 2;
                if (numbers[mid] == to_find) {
                    return { i + 1, mid + 1 };
                } else if (numbers[mid] > to_find) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
        }

        return { -1, -1 };
    }
};


// [1,2,7,11,15]