int M = 1e9 + 7;
using LL = long long;

class Solution {
public:
    int countStableSubsequences(vector<int>& nums) {
        int n = nums.size();
        LL e1 = 0; // # sequences that ends with 1 even number
        LL e2 = 0; // # sequences that ends with 2 even numbers
        LL o1 = 0; // # sequences that ends with 1 odd number
        LL o2 = 0; // # sequences that ends with 2 odd numbers

        for (int i = 0; i < n; i++) {
            // odd
            if (nums[i] % 2 == 1) {
                LL next_o1 = (o1 + (e1 + e2 + 1)) % M;
                LL next_o2 = (o1 + o2) % M;
                o1 = next_o1;
                o2 = next_o2;
            }
            // even
            else {
                LL next_e1 = (e1 + (o1 + o2 + 1)) % M;
                LL next_e2 = (e1 + e2) % M;
                e1 = next_e1;
                e2 = next_e2;
            }
        }

        return (int)((o1 + o2 + e1 + e2) % M);
    }
};

