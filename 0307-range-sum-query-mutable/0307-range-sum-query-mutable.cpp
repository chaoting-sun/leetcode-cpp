class NumArray {
private:
    vector<int> prefix;
    vector<int> nums;
public:
    NumArray(vector<int>& nums) {
        this->nums = nums;
        int n = nums.size();
        prefix.reserve(n + 1);
        for (int i = 0; i < n; i++) prefix[i + 1] = prefix[i] + nums[i];
    }
    
    void update(int index, int val) {
        if (index < 0 || index >= nums.size()) return;

        int diff = val - nums[index];
        // update nums
        nums[index] = val;
        // update prefix
        for (int i = index + 1; i <= nums.size(); i++) {
            prefix[i] += diff;
        }
    }
    
    int sumRange(int left, int right) {
        return prefix[right + 1] - prefix[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */