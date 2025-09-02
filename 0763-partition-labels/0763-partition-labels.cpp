class Solution {
public:
    // Approach: Greedy
    // any same characters should be in the same group, so if there is a string like a....a...,
    // the a....a should be in the same group. if there is a character c in the center and another
    // c at the right, like a..c..a..c.., then a..c..a..c should be in the same group.
    // in other word, if a substring form a group, for each character appears more than once, their
    // maximum position should be bounded in the group.
    // So, the method is to store the maximum position of the characters in a hash map max_ids.
    // we start from index = 0, and set end as the max_ids[start]. then we keep looping from start
    // to the end and keeps updating the end. when start == end. then all existing characters should
    // be bounded in this group. then we set start = end + 1 for the next round.
    
    // Time: O(n)
    // Space: O(k). k is the number of distinct characters in s

    vector<int> partitionLabels(string s) {
        int n = s.size();
        if (n == 0) return {};
        
        unordered_map<int, int> max_ids;

        for (int i = 0; i < n; i++) {
            max_ids[s[i]] = i;
        }

        vector<int> ans;

        int start = 0;
        while (start < n) {
            int end = max_ids[s[start]];
            int idx = start;
            while (idx < end) {
                idx++;
                end = max(end, max_ids[s[idx]]);
            }
            ans.push_back(end - start + 1);
            start = end + 1;
        }

        return ans;
    }
};