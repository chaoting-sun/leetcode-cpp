class Solution {
public:
    vector<vector<int>> ans;

    void search(vector<int> curr, vector<int>& selections) {
        if (selections.size() == 0) {
            ans.push_back(curr);
            return;
        }

        for (int i = 0; i < selections.size(); i++) {
            curr.push_back(selections[i]);

            vector<int> new_selections;
            for (int j = 0; j < selections.size(); j++) {
                if (j == i) continue;
                new_selections.push_back(selections[j]);
            }

            search(curr, new_selections);
            curr.pop_back();
        }

    }

    vector<vector<int>> permute(vector<int>& nums) {
        search(vector<int>(), nums);
        return ans;
    }
};