class Solution {
public:
    // Problem: Count triples (i, j, k) with i < j < k such that
    //          nums[i] + nums[j] + nums[k] < target.
    //
    // Intuition:
    // If we sort nums, we can fix the first element and use a two-pointer scan
    // to count valid pairs for the remaining subarray in linear time.
    //
    // Approach:
    // 1) Sort nums (ascending).
    // 2) For each i in [0 .. n-3]:
    //      - Let sumUpper = target - nums[i]. We need nums[left] + nums[right] < sumUpper.
    //      - Set left = i + 1, right = n - 1.
    //      - While (left < right):
    //          * If nums[left] + nums[right] < sumUpper:
    //                Then for this fixed left, every index t in (left, right] also works
    //                because nums[t] <= nums[right] (array is sorted).
    //                So we can add (right - left) to the count and do left++.
    //          * Else (the pair is too large), do right-- to reduce the sum.
    //
    // Complexity:
    // - Time: O(n log n) to sort + O(n^2) two-pointer search ⇒ O(n^2)
    // - Space: O(1) extra (in-place sort).

    int threeSumSmaller(vector<int>& nums, int target) {
        int n = nums.size();
        if (n <= 2) return 0;
        
        sort(nums.begin(), nums.end());
        int count = 0;

        for (int i = 0; i < n - 2; i++) {
            int sumUpperBound = target - nums[i];
            int left = i + 1, right = n - 1;
            while (left < right) {
                if (nums[left] + nums[right] >= sumUpperBound) {
                    right--;
                    continue;
                }
                count += right - left;
                left++;
            }
        }
        return count;
    }

    // For next practice

    // int threeSumSmaller(vector<int>& nums, int target) {

    // }
};

// ex: [-2,0,1,3], target = 2

// i = 0
// sumUpperBound = 4
// left = 1, right = 3
// while loop:
// 0 + 3 < 4
// count += 3 - 1 -> count = 2
// left = 2
// 1 + 3 >= 4
// right = 2
// break