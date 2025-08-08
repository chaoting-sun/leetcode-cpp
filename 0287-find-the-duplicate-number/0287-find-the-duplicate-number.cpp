class Solution {
public:
    // Approach1: Marking on an array of slots
    // Time: O(n)
    // Space: O(n)

    // int findDuplicate(vector<int>& nums) {
    //     int sz = nums.size();
    //     vector<int> slot(sz);

    //     for (int i = 0; i < sz; i++) {
    //         slot[nums[i]]++;
    //     }

    //     for (int i = 1; i < sz; i++) {
    //         if (slot[i] > 1) return i;
    //     }
    //     return -1;
    // }

    // Approach2: fast and slow + Floyd's cycle detection
    // Time: O(n)
    // Space: O(1)

    int findDuplicate(vector<int>& nums) {
        int fast = nums[0], slow = nums[0];
        while (true) {
            fast = nums[nums[fast]];
            slow = nums[slow];
            if (fast == slow) break;
        }

        int curr = nums[0];
        while (curr != slow) {
            curr = nums[curr];
            slow = nums[slow];
        }

        return curr;
    }
};
