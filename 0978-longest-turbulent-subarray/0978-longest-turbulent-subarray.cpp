class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n = arr.size();
        if (n == 0) return 0;
        
        vector<int> largerOddLength(n, 1), largerEvenLength(n, 1);
        int maxLength = 1;
        
        for (int i = 1; i < n; i++) {
            if ((i % 2 == 1 && arr[i - 1] < arr[i]) ||
                (i % 2 == 0) && arr[i - 1] > arr[i]) {
                largerOddLength[i] = largerOddLength[i - 1] + 1;
                maxLength = max(maxLength, largerOddLength[i]);
            }
        }

        for (int i = 1; i < n; i++) {
            if ((i % 2 == 1 && arr[i - 1] > arr[i]) ||
                (i % 2 == 0) && arr[i - 1] < arr[i]) {
                largerEvenLength[i] = largerEvenLength[i - 1] + 1;
                maxLength = max(maxLength, largerEvenLength[i]);
            }
        }

        return maxLength;
    }
};