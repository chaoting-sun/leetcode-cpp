class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int length = nums.size();
        if (length <= 2) return length;

        int left = 2;
        int right = 2;
        while (right < length) {
            if (nums[left - 2] == nums[right]) {
                right++;
            } else {
                swap(nums[left], nums[right]);
                left++;
                right++;
            }
        }
        return left;
    }
};

// happy path:
// nums = [2,2,3,3,3]
// length = 5
// l    r   action
// 2    2   swap -> [2,2,3,3,3], r++, l++
// 3    3   swap -> [2,2,3,3,3], r++, l++
// 4    4   swap -> [2,2,3,3,3], r++, l++
// 4    5   r++
// 4    6
// < returns 4

// base case:
// nums = [1] -> returns 1
// nums = [1,2] -> returns 2
// nums = [1,2,3,4]
// l    r   action
// 2    2   swap -> [1,2,3,4], l++, r++
// 3    3   swap -> [1,2,3,4], l++, r++
// 4    4
// < returns 4

// trap case:
// nums = [2,2,2,3,3]
// trace:
// length = 5
// l    r   action
// 2    2   r++
// 2    3   swap -> [2,2,3,2,3], l++, r++
// 3    4   swap -> [2,2,3,3,2], l++, r++
// 4    5
// < returns 4
