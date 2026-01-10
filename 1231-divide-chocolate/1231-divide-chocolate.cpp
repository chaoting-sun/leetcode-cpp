class Solution {
private:
    bool canSplit(vector<int>& sweetness, int k, int lower_bound) {
        int pieces = 0;
        int current = 0;
        for (int i = 0; i < sweetness.size(); i++) {
            current += sweetness[i];
            if (current >= lower_bound) {
                pieces++;
                current = 0;
            }
        }
        return pieces >= k + 1;
    }

public:
    int maximizeSweetness(vector<int>& sweetness, int k) {
        int n = sweetness.size();
        if (n < k + 1) return -1;
        
        int min_val = sweetness[0];
        int total_val = 0;
        for (int i = 0; i < n; i++) {
            min_val = min(min_val, sweetness[i]);
            total_val += sweetness[i];
        }

        int left = min_val;
        int right = total_val; // k can be 0
        // T...T F...F
        // l   l
        //     r    r
        
        while (left < right) {
            int mid = left + (right - left + 1) / 2; // 尋找最大值時需要這樣
            if (canSplit(sweetness, k, mid)) {
                left = mid;
            } else {
                right = mid - 1;
            }
        }
        return right;
    }
};

// [1,2,3, 4 ,5 ,6, 7, 8,9]

// total sweetness
//  min: min element in sweetness
//  max: sum of sweetness

// min sweetness -> group >= k + 1 -> valid -> try larger sweetness
//                  group < k + 1  -> invalid -> try smaller sweetness
// [T T T .... F F F F]
// find the last sweetness that is valid