class Solution {
public:
    // Greedy
    // iterate the triplets, looking for those with triplets[i] <= target[i], i = 0~2,
    // and takes the max. of each position. if the res is equal to target, then return true
    
    // Time: O(n)
    // Space: O(1)

    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        vector<int> res{ 0, 0, 0 };

        for (vector<int>& t: triplets) {
            if (t[0] <= target[0] && t[1] <= target[1] && t[2] <= target[2]) {
                for (int i = 0; i < 3; i++) res[i] = max(res[i], t[i]);
            }
        }

        for (int i = 0; i < 3; i++) {
            if (res[i] != target[i]) return false;
        }
        return true;
    }
};