class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& arr) {
        int n = arr.size();
        int pivot = n - 2;
        while (pivot >= 0 && arr[pivot] <= arr[pivot + 1]) {
            pivot--;
        }

        vector<int> ans(arr);
        if (pivot == -1) {
            return ans;
        }
        
        int nextSmallerIdx = n - 1;
        while (pivot < nextSmallerIdx && arr[pivot] <= arr[nextSmallerIdx]) {
            nextSmallerIdx--;
        }
        while (arr[nextSmallerIdx - 1] == arr[nextSmallerIdx]) {
            nextSmallerIdx--;
        }
        swap(ans[pivot], ans[nextSmallerIdx]);
        return ans;
    }
};
