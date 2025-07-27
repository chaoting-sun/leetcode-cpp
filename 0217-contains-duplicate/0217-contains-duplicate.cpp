class Solution {
public:
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