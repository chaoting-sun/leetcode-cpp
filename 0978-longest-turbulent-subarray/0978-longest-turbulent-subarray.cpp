class Solution {
public:
    // Approach: DP
    // Time: O(n)
    // Space: O(n)

    // int maxTurbulenceSize(vector<int>& arr) {
    //     int n = arr.size();
    //     if (n == 0) return 0;
        
    //     vector<int> largerOddLength(n, 1), largerEvenLength(n, 1);
    //     int maxLength = 1;
        
    //     for (int i = 1; i < n; i++) {
    //         if ((i % 2 == 1 && arr[i - 1] < arr[i]) ||
    //             (i % 2 == 0) && arr[i - 1] > arr[i]) {
    //             largerOddLength[i] = largerOddLength[i - 1] + 1;
    //             maxLength = max(maxLength, largerOddLength[i]);
    //         }
    //     }

    //     for (int i = 1; i < n; i++) {
    //         if ((i % 2 == 1 && arr[i - 1] > arr[i]) ||
    //             (i % 2 == 0) && arr[i - 1] < arr[i]) {
    //             largerEvenLength[i] = largerEvenLength[i - 1] + 1;
    //             maxLength = max(maxLength, largerEvenLength[i]);
    //         }
    //     }

    //     return maxLength;
    // }

    // Approach: DP
    // Time: O(n)
    // Space: O(1)

    // int maxTurbulenceSize(vector<int>& arr) {
    //     int n = arr.size();
    //     if (n == 0) return 0;
        
    //     int largerOddLength = 1, largerEvenLength = 1;
    //     int maxLength = 1;
        
    //     for (int i = 1; i < n; i++) {
    //         if ((i % 2 == 1 && arr[i - 1] < arr[i]) ||
    //             (i % 2 == 0) && arr[i - 1] > arr[i]) {
    //             largerOddLength++;
    //             maxLength = max(maxLength, largerOddLength);
    //         } else {
    //             largerOddLength = 1;
    //         }
    //     }

    //     for (int i = 1; i < n; i++) {
    //         if ((i % 2 == 1 && arr[i - 1] > arr[i]) ||
    //             (i % 2 == 0) && arr[i - 1] < arr[i]) {
    //             largerEvenLength++;
    //             maxLength = max(maxLength, largerEvenLength);
    //         } else {
    //             largerEvenLength = 1;
    //         }
    //     }

    //     return maxLength;
    // }

    // Approach: DP
    // Time: O(n)
    // Space: O(1)

    int maxTurbulenceSize(vector<int>& arr) {
        int n = arr.size();
        if (n == 0) return 0;
        
        int incTail = 1, decTail = 1, ans = 1;
        for (int i = 1; i < n; i++) {
            if (arr[i - 1] < arr[i]) {
                incTail = decTail + 1;
                decTail = 1;
            } else if (arr[i - 1] > arr[i]) {
                decTail = incTail + 1;
                incTail = 1;
            } else {
                incTail = 1;
                decTail = 1;
            }
            ans = max(ans, max(incTail, decTail));
        }

        return ans;
    }
};