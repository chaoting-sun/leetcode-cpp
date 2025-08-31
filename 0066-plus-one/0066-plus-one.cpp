class Solution {
public:
    // Approach: loop from right to left and maintain a flag to indicate if we need to plus 1 in that position
    // Time: O(n)
    // Space: O(1)

    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        bool plus1 = true;
        vector<int> ans(n);
        
        for (int i = n - 1; i >= 0; i--) {
            ans[i] = plus1 ? digits[i] + 1 : digits[i];
            plus1 = false;
            
            if (ans[i] >= 10) {
                ans[i] -= 10;
                plus1 = true;
            }
        }

        if (plus1) {
            ans.insert(ans.begin(), 1);
        }

        return ans;
    }
};