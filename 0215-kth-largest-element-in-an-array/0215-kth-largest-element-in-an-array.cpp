class Solution {
public:
    // Intuition: we need to get the k th largest element without sorting,
    // so we need a data structure that enable us to know if an element is
    // smaller than or larger than another one -> heap
    // Approach: Min Heap
    // Time: O(n*logk)
    // Space: O(k)

    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;

        for (int val: nums) {
            pq.push(val);
            if (pq.size() > k) {
                pq.pop();
            }
        }
        return pq.top();
    }

    // quick select
    // Time: O(n) in average case. O(n^2) in worst case (array is sorted)
    // Space: O(1)

    // int findKthLargest(vector<int>& nums, int k) {
    //     return quickSelect(nums, k, 0, nums.size() - 1);
    // }

    // int quickSelect(vector<int>& nums, int k, int left, int right) {
    //     if (left == right) {
    //         return nums[left];
    //     }

    //     int pivot_index = partition(nums, left, right);
    //     int rank = pivot_index - left + 1;

    //     if (rank == k) {
    //         return nums[pivot_index];
    //     } else if (rank > k) {
    //         return quickSelect(nums, k, left, pivot_index - 1);
    //     } else {
    //         return quickSelect(nums, k - rank, pivot_index + 1, right);
    //     }
    // }

    // int partition(vector<int>& nums, int left, int right) {
    //     int pivot = nums[right];

    //     int i = left;
    //     for (int j = left; j < right; j++) {
    //         if (nums[j] >= pivot) {
    //             swap(nums[i], nums[j]);
    //             i++;
    //         }
    //     }

    //     swap(nums[i], nums[right]);
    //     return i;
    // }
};