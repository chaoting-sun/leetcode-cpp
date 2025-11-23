class Solution {
public:
    int maxBalancedSubarray(vector<int>& nums) {
        int n = nums.size();

        vector<int> xorPrefix(n);
        xorPrefix[0] = nums[0];
        for (int i = 1; i < n; i++) {
            xorPrefix[i] = xorPrefix[i - 1] ^ nums[i];
        }
        vector<int> oddToEvenPrefix(n);
        oddToEvenPrefix[0] = nums[0] % 2 == 1 ? 1 : -1;
        for (int i = 1; i < n; i++) {
            oddToEvenPrefix[i] = oddToEvenPrefix[i - 1] + (nums[i] % 2 == 1 ? 1 : -1);
        }

        int ans = 0;
        map<pair<int,int>, int> mp;
        mp[{ 0, 0 }] = -1;
        for (int i = 0; i < n; i++) {
            pair<int, int> p(xorPrefix[i], oddToEvenPrefix[i]);
            if (mp.count(p)) {
                ans = max(ans, i - mp[p]);
            } else {
                mp[p] = i;
            }
        }
        return ans;
    }
};

// prefix[i] = [nums[0] ^ nums[1] ... nums[i]]
// [j..i]
// prefix[i] ^ prefix[j - 1] -> XOR of [j..i]
// prefix[i] == prefix[j - 1] -> prefix[i] ^ prefix[j - 1] == 0

//  0 1 2 3 4 5
// [0 1 2 3 0 2 .... 2]
// map -> value -> index at first time

// prefixOddToEven -> prefixOddToEven[i] -> [0 .. i] #odd - #even
// map -> value -> index at firt time

// => map<value1, value2> -> the first time
