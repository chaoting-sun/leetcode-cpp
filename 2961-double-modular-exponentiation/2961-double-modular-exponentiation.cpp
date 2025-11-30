class Solution {
public:
    vector<int> getGoodIndices(vector<vector<int>>& variables, int target) {
        vector<int> ans;
        int n = variables.size();
        for (int i = 0; i < n; i++) {
            int a = variables[i][0];
            int b = variables[i][1];
            int c = variables[i][2];
            int m = variables[i][3];
            
            int res = 1;
            for (int j = 0; j < b; j++) {
                res = (res * a) % 10;
            }
            int tmp = res;
            res = 1;
            for (int j = 0; j < c; j++) {
                res = (res * tmp) % m;
            }
            if (res == target) ans.push_back(i);
        }
        return ans;
    }
};