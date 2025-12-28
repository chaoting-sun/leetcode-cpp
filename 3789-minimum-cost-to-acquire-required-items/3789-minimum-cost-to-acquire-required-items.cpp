using ll = long long;

class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        if (need1 + need2 == 0) return 0;

        ll overlap_both_need = min(need1, need2);
        ll overlap_unit_cost = min((ll)costBoth, (ll)cost1 + cost2);
        
        ll min_cost = overlap_unit_cost * overlap_both_need;

        if (need1 > need2) {
            min_cost += (ll)(need1 - need2) * min(costBoth, cost1);
        } else {
            min_cost += (ll)(need2 - need1) * min(costBoth, cost2);
        }
        return min_cost;
    }
};