class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<int,int> lastOccurrence;
        for (int i = 0; i < s.size(); i++) {
            lastOccurrence[s[i]] = i;
        }
        
        vector<int> ans;
        int currentL = 0, maxR = 0;
        for (int i = 0; i < s.size(); i++) {
            maxR = max(maxR, lastOccurrence[s[i]]);
            if (maxR == i) {
                ans.push_back(maxR - currentL + 1);
                currentL = i + 1;
            }
        }
        return ans;
    }
};

//  0123
// 'abac'
//  l
//    r


// { a: 2, b: 1, c: 3 }