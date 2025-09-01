class Solution {
public:
    // Approach:
    // Time: O(nlogm)
    // inserting each element into a map takes O(logm) time, where m is the number of unique elements. for n elements it costs O(nlogm)
    // the inner loop runs groupSize times and each operation is O(logm). the while loop runs n/groupSize times. so the time is O(nlogm)

    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if (n % groupSize != 0) return false;

        map<int, int> cnts;
        for (int i = 0; i < n; i++) {
            cnts[hand[i]]++;
        }

        while (n > 0) {
            auto min_val = begin(cnts)->first;

            for (int i = 0; i < groupSize; i++) {
                int curr_val = min_val + i;
                if (!cnts.count(curr_val)) return false;
                cnts[curr_val]--;
                if (cnts[curr_val] == 0) cnts.erase(curr_val);
            }
            n -= groupSize;
        }
        
        return true;
    }
};