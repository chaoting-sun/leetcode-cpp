class Solution {
private:
    int subarrayWithAtMostK(vector<int>& nums, int k) {
        if (k < 0) return 0;
        
        vector<int> num_count(2 * 1e4 + 1);
        int total_subarray_count = 0;
        int distinct_count = 0;
        
        int left = 0;
        for (int right = 0; right < nums.size(); right++) {
            if (num_count[nums[right]] == 0) distinct_count++;
            num_count[nums[right]]++;
            while (distinct_count > k) {
                num_count[nums[left]]--;
                if (num_count[nums[left]] == 0) distinct_count--;
                left++;
            }
            total_subarray_count += right - left + 1;
        }
        cout << total_subarray_count << endl;
        return total_subarray_count;
    }

public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return subarrayWithAtMostK(nums, k) - subarrayWithAtMostK(nums, k - 1);
    }
};

// test case: nums = [1,2,1,2,3], k = 2
//                    0 1 2 3 4
// subarrayWithAtMostK(2) - subarrayWithAtMostK(1)
// subarrayWithAtMostK(1)
//  l = 0
//  r = 0, distinct = 1, count[1] = 1, total = 1
//  r = 1, distinct = 2, count[2] = 1
//      count[1] = 0, distinct = 1, left = 1, total = 2

// Submit Error
// RE:
// num_count[right] -> num_count[nums[right]]
// WA:
