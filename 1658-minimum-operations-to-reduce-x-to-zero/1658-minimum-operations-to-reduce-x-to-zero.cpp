// ## Understand

// What is the max length of nums? -> 1 <= nums.length <= 10^5
// what is the range of x? -> 1 <= x <= 10^9

// ## Match

// The brute-force method is to try every possible combinations to sum them up to x, and return
// -1 if there is no such combination.
// We can try an indirect method. Finding the minimum number of operations to reduce x to 0 is
// equivalent to finding the longest subarray which sum is total sum of array - x. So, we can
// use two pointer in this problem.


// ## Plan

// I will firstly calculate the total sum of nums, and let subarray_sum to be the total sum minus x
// Then, I initialize two pointers left and right at index 0. I will sum up the interval between
// left and right, and check If the current sum can be the subarray_sum. Every time this happens,
// I update the minimum of a global value.
// Specifically, I iterate the array using the right pointer and sum up the values. For each step,
// if the current sum is larger than subarray_sum, I contract the subarray by moving the left pointer.


// Implementation

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int length = nums.size();
        int total_sum = 0;
        for (int n: nums) total_sum += n;
        int subarray_sum = total_sum - x;

        int max_subarray_length = INT_MIN;
        int current_sum = 0;
        int left = 0;
        // search all subarray that sums up to subarray_sum
        for (int right = 0; right < length; right++) {
            current_sum += nums[right];
            while (left <= right && current_sum > subarray_sum) {
                current_sum -= nums[left];
                left++;
            }
            if (current_sum == subarray_sum) {
                max_subarray_length = max(max_subarray_length, right - left + 1);
            }
        }

        return max_subarray_length == INT_MIN ? -1 : length - max_subarray_length;
    }
};

// base case: nums = [5], x = 3 -> -1
// trace:
// subarray_sum = 2
// for loop
// right = 0
// current_sum = 5
// current_sum = 0, left = 1
// < return -1

// happy case: nums = [1,1,2], x = 2 -> 1
// trace:
// total_sum = 4
// subarray_sum = 2
// for loop
//  right = 0
//  current_sum = 1
//  while: 1 > 2? no
//  right = 1
//  current_sum = 2
//  while: 2 > 2? no
//  max_subarray_length = 2
//  right = 2
//  current_sum = 4
//  while: 0<=2 and 4>2. yes
//      current_sum = 3
//      left = 1
//  while: 1<=2 and 3>2. yes
//      current_sum = 2
//      left = 2
//  max_subarray_length = max(2, 1) = 2
// < returns 3 - 2 = 1


// Evaluation

// Time: O(N). Each element will be at most visited twice.
// Space: O(1)