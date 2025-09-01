class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if (n % groupSize != 0) return false;

        map<int, int> cnts;
        for (int i = 0; i < n; i++) {
            cnts[hand[i]]++;
        }

        while (n) {
            auto min_val = begin(cnts)->first;
            if (!cnts.count(min_val + 1) || !cnts.count(min_val + 2)) {
                return false;
            }

            cnts[min_val]--;
            cnts[min_val + 1]--;
            cnts[min_val + 2]--;

            if (cnts[min_val] == 0) cnts.erase(min_val);
            if (cnts[min_val + 1] == 0) cnts.erase(min_val + 1);
            if (cnts[min_val + 2] == 0) cnts.erase(min_val + 2);
            
            n -= 3;
        }
        
        return true;
    }
};