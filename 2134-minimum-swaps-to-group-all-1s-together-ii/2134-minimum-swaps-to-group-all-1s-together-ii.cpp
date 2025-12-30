// ## Understand

// What is the length range of nums? -> 1 <= nums.length <= 10^5
// Is it possible that nums contains values that are not 0 or 1? -> No.


// ## Match

// Me:
// The first method I come up with is BFS. starting from the input nums, I
// change the state of nums by swapping one pair each time, everytime I
// check if all 1's is together. In worst case, there are C^n_k, where n
// is the length of nums and k is the number of 1s. every check needs O(n)
// time. so this method is not possible due to the constraint.

// Interviewer:
// Forget about how you move the 1s for a second. Imagine the problem is already solved.
// If the input array has, say, Total_Ones count of 1s, what does the final array look like?
// It will be a contiguous block of 1s. How long is that block?
// If you place a "window" of that specific length anywhere over the array, how can you instantly tell me how many swaps are needed to make that specific window full of 1s?

// Me:
// I think we can map this problem as a sliding window problem.
// As we can swap any two distinct positions, suppose that we know the final state of swapped
// result, and there are n 0s, then the minimum swaps should be n. As the length of nums is
// in 10^5, we can use a fix-length sliding window, viewing each window as the final result
// and recording the minimum swaps.


// ## Plan

// firstly, I compute the number of 1's. This decides the window size.
// then, I run a sliding window with the window size, and I maintain a variable zero_count that
// represents the number of zeros in the window, or the number of minimum swaps. I use a global
// variable min_swaps to update the global minimum swaps every time.


// ## Implementation

class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int length = nums.size();
        if (length == 0) return 0;

        // count the 1s to decide the window size
        int window_size = 0;
        for (int n: nums) window_size += n;

        // compute the first window for the convenience of running sliding window later
        int zero_count = 0;
        int min_swaps = INT_MAX;
        for (int i = 0; i < window_size; i++) {
            if (nums[i] == 0) zero_count++;
        }
        min_swaps = min(min_swaps, zero_count);

        // run sliding window
        for (int right = window_size; right < length + window_size - 1; right++) {
            // to correctly access the value
            int real_right = right % length;
            // the first element in current window is at right - window_size + 1
            int prev_left = right - window_size;
            
            // update the zero count in the current window
            if (nums[real_right] == 0) zero_count++;
            if (nums[prev_left] == 0) zero_count--;

            min_swaps = min(min_swaps, zero_count);
        }

        return min_swaps;
    }
};

// ## Review

// test case: [1 0 0 1] -> should return 0
//             0 1 2 3
// trace:
// window_size = 2
// zero_count = 1, min_swaps = 1
// for loop: right = 2 ~ 4
// right = 2, zero_count = 1 + 1 - 0 = 2
// right = 3, zero_count = 2 + 0 - 1 = 1
// right = 4, zero_count = 1 + 0 - 1 = 0 -> update: min_swaps = 0
// < returns 0

// test case: [1 0 1 0] -> should return 1
//             0 1 2 3
// trace:
// window_size = 2
// zero_count = 1
// min_swaps = 1
// for loop: right = 2 ~ 4
// right = 2, zero_count = 1 + 0 - 0 = 1
// right = 3, zero_count = 1 + 1 - 1 = 1
// right = 4, zero_count = 1 + 0 - 0 = 1
// < returns 1

// base case: [] < returns 0
// base case: [1]
// trace: window_size = 1, min_swaps = 0 < returns 0
// base case: [0]
// trace: window_size = 1, zero_count = 1, min_swaps = 1 < returns 1


// ## Evaluation

// Time: O(n). the movement of sliding window is linear and for each window it's constant time
// Space: O(1)


// ## Submit Errors

// for (int right = window_size; right < length + window_size - 1) {
// to
//for (int right = window_size; right < length + window_size - 1; right++) {