class Solution {
public:
    // brute-force -> TLE
    // time: O(n**2)
    // space: O(1)

    // bool containsDuplicate(vector<int>& nums) {
    //     int n = nums.size();
    //     for (int i = 0; i < n - 1; i++) {
    //         for (int j = i + 1; j < n; j++) {
    //             if (nums[i] == nums[j]) {
    //                 return true;
    //             }
    //         }
    //     }
    //     return false;
    // }

    // sort nums and compare adjacent numbers
    // time: O(n*lg(n)) -> sorting cost n*lg(n) time
    // space: O(n)

    // bool containsDuplicate(vector<int>& nums) {
    //     vector<int> nums_copy = nums;

    //     sort(nums_copy.begin(), nums_copy.end());
    //     for (int i = 0; i < nums.size() - 1; i++) {
    //         if (nums_copy[i] == nums_copy[i+1]) {
    //             return true;
    //         }
    //     }
    //     return false;
    // }

    // store distinct values in set
    // time: O(n) -> iterate all elements in nums at most
    // space: O(n) -> store at most n distinct element in set

    bool containsDuplicate(vector<int>& nums) {
        set<int> record{};
        for (int n: nums) {
            if (record.find(n) != record.end()) {
                return true;
            }
            record.insert(n);
        }
        return false;
    }
};