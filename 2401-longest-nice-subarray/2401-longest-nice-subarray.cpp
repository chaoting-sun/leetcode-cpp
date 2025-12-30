// ## understand

// the length range of nums? -> 1 <= nums.length <= 10^5
// the range of the elements in nums? -> 1 <= nums[i] <= 10^9


// ## Match

// me:
// The bruteforce method is try every combination of the subarray, which will take O(N^2), and for
// subarray we check by testing all pairs, which also cost O(N^2). Totally, it would take O(N^4)

// interviewer's hint:
// What standard algorithm pattern is almost always the first choice for "longest contiguous subarray" problems?
// If Number A has a bit set at position 2 (binary 100), and Number B also has a bit set at position 2, then A & B is not 0.

// me:
// I think we should map it as a sliding window problem, as it requires us to return the length of the longest nice subarray.
// also, once there are two values in the subarray which has 1 in the same position of bit representation, this array
// is invalid, so we can contract the subarray until it changes to valid. The monotonic property is the condition
// that we can apply sliding window


// ## Plan

// we need to use a vector to store if each bit has existed in the subarray. as the range of nums is positive, and is less or
// equal to 10^9, we can create a vector of length 31 to store the bit.
// I will run a standard sliding window approach with the left and right pointer, and use a global variable max_length store
// update the maximum subarray.
// every time I expand the right pointer, I update the vector. when we find that adding a value causes invalid result,
// I will shrink the left pointer until the subarray is valid.


// ## Implementation

class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        // let's handle the base case for early stop
        int length = nums.size();
        if (length == 0) return 0;

        // create a bit vector to record the usage of each bit in the current subarray
        vector<int> bit_usage(31);

        // run the sliding window
        int left = 0;
        int right = 0;
        int max_length = 0;

        while (right < length) {
            // we interate through all bits, check if any bit is invalid
            for (int i = 0; i <= 30; i++) {
                int new_bit = (nums[right] >> i) & 1;
                // we need to handle the invalidity immediately, shrinking the left pointer to make the subarray valid
                while (new_bit == 1 && bit_usage[i] == 1) {
                    // we flip the 1 bit to 0 if it is contributed by the current value
                    for (int j = 0; j <= 30; j++) {
                        int old_bit = (nums[left] >> j) & 1;
                        if (old_bit == 1) bit_usage[j] = 0;
                    }
                    left++;
                }
                if (new_bit > 0) bit_usage[i] = new_bit;
            }

            max_length = max(max_length, right - left + 1);
            right++;
        }

        return max_length;
    }
};


// ## Review

// [5, 2, 1] -> [101, 010, 001] (ans = 2)
// bit_usage = [1, 0, 1]
// right = 1
// bit_usage = [1, 1, 1]
// max_length = 2
// right = 2
// i = 2
// bit_usage = [0, 1, 0]
// bit_usage = [0, 1, 1]
// max_length = 2
// < returns 2

// test case: [3,3] -> [011, 011]
// bit_usage = [1, 1, 0, ...]
// right = 1
// new_bit = 3 >> 0 & 1 = 1
// shrink from left
// bit_usage = [0, 0, 0]
// left = 1
// bit_usage = [1, 0, 0]
// bit_usage = [1, 1, 0]

// base case: [3] -> [011]
// bit_usage = [1, 1, 0, ...]
// max_length = 1
// < returns 1


// Evaluation

// Time: in sliding window, each element is at most processed twice
// the time will be O(n) * 31 * 2 = O(n). it is linear time
// the space is contant. O(1)