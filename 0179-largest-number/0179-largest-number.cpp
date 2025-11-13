class Solution {
public:
    string largestNumber(vector<int>& nums) {
        int n = nums.size();
        vector<string> numsStr(n);
        for (int i = 0; i < n; i++) {
            numsStr[i] = to_string(nums[i]);
        }
        sort(numsStr.begin(), numsStr.end(), [](string& a, string& b) {
            return a + b > b + a;
        });
        if (numsStr[0] == "0") return "0";
        string ans = "";
        for (string& str: numsStr) {
            ans += str;
        }
        return ans;
    }
};
